// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-10801

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MAJOONI ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define int long long
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> c_set;

#define tu tuple<int, int, int>

bool solve()
{
    string txt;
    vector<int> price;
    getline(cin, txt);
    if (!txt.size())
        return false;

    int s = txt.find(' '), ll, x, y;
    int len = stoll(txt.substr(0, s)), en = stoll(txt.substr(s + 1, txt.size() - s - 1));

    vector<int> el[len], nums[105];

    price.resize(len);
    for (int i{}; i < len; ++i)
        cin >> price[i];

    cin.ignore();
    for (int i{}; i < len; ++i)
    {
        getline(cin, txt);

        vector<int> sp;
        for (int i{}; i < txt.size(); ++i)
            if (txt[i] == ' ')
                sp.push_back(i);

        ll = sp.size();
        if (!ll)
        {
            x = stoll(txt);
            el[i].push_back(x);
            nums[x].push_back(i);
            continue;
        }

        x = stoll(txt.substr(0, sp[0]));
        el[i].push_back(x);
        nums[x].push_back(i);
        for (int j{1}; j < ll; ++j)
        {
            x = stoll(txt.substr(sp[j - 1] + 1, sp[j] - sp[j - 1] - 1));
            el[i].push_back(x);
            nums[x].push_back(i);
        }
        x = stoll(txt.substr(sp[ll - 1] + 1, txt.size() - sp[ll - 1] - 1));
        el[i].push_back(x);
        nums[x].push_back(i);
    }

    priority_queue<tu, vector<tu>, greater<tu>> qu;
    int cost[105];
    memset(cost, -1, sizeof cost);
    qu.push({0, 0, -1});
    cost[0] = 0;

    while (!qu.empty())
    {
        auto n = qu.top();
        int node = get<1>(n);
        int co = get<0>(n);
        int e = get<2>(n);
        qu.pop();

        if (co != cost[node])
            continue;

        for (auto fl: nums[node])
        {
            for (auto way : el[fl])
            {
                int coWay = cost[node] + (abs(way - node) * price[fl]);
                if (~e && fl != e)
                    coWay += 60;

                if (cost[way] == -1 || cost[way] > coWay)
                {
                    cost[way] = coWay;
                    qu.push({cost[way], way, fl});
                }
            }
        }
    }

    if (!~cost[en]) 
        cout << "IMPOSSIBLE" << endl;
    else 
        cout << cost[en] << endl;

    return true;
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int tc;
    // cin >> tc;
    while (solve())
        true;
}