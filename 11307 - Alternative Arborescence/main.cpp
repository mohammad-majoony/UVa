// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-11307

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

int const N = 1e4 + 5;
int len;
vector<int> ed[N];
int mem[N][11];

int dfs(int cu, int add)
{
    if (~mem[cu][add])
        return mem[cu][add];

    int res{add}, mini;
    for (auto n : ed[cu])
    {
        mini = LLONG_MAX;
        for (int i{1}; i <= 10; ++i)
        {
            if (i == add)
                continue;
            mini = min(mini, dfs(n, i));
        }
        res += mini;
    }
    return mem[cu][add] = res;
}

bool solve()
{
    memset(mem, -1, sizeof mem);
    set<int> findR;
    int root{}, x, y, mini{LLONG_MAX};
    string txt;
    if (!len)
        return true;

    for (int i{}; i < len + 5; ++i)
        ed[i].clear();

    cin.ignore();
    for (int i{}; i < len; ++i)
    {
        getline(cin, txt);
        vector<int> sp;
        for (int i{}; i < txt.size(); ++i)
            if (txt[i] == ' ')
                sp.push_back(i);
        if (!sp.size())
            continue;

        x = stoll(txt.substr(0, sp[0]));
        for (int i{1}; i < sp.size(); ++i)
        {
            y = stoll(txt.substr(sp[i - 1] + 1, sp[i] - sp[i - 1] - 1));
            ed[x].push_back(y);
            findR.insert(y);
        }
        if (txt.size() - sp[sp.size() - 1] - 1 > 0)
        {
            y = stoll(txt.substr(sp[sp.size() - 1] + 1, txt.size() - sp[sp.size() - 1] - 1));
            ed[x].push_back(y);
            findR.insert(y);
        }
    }

    for (auto n : findR)
    {
        if (n != root)
            break;
        root++;
    }

    for (int i{1}; i <= 10; ++i)
        mini =  min({mini, dfs(root, i)});
    cout << mini << endl;

    cin.ignore();
    cin >> len;
    return false;
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> len;
    // cin >> tc;
    while (true)
    {
        if (solve())
            break;
    }
}