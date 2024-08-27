// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-10171

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

bool solve()
{
    // tuple<char, bool, int> == destinition, for young?, energy const
    map<char, vector<tuple<char, bool, int>>> ed;
    int r, en;
    cin >> r;
    if (!r)
        return true;

    char ch[4], s, e;
    for (int i{}; i < r; ++i)
    {
        for (int j{}; j < 4; ++j)
            cin >> ch[j];
        cin >> en;

        ed[ch[2]].push_back(make_tuple(ch[3], ch[0] == 'Y', en));
        if (ch[1] == 'B')
            ed[ch[3]].push_back(make_tuple(ch[2], ch[0] == 'Y', en));
    }

    map<char, int> y, m;
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> qu;
    cin >> s >> e;

    map<char, bool> vis;
    qu.push(make_pair(0, s));
    vis[s] = true;
    y[s] = 0;

    while (!qu.empty())
    {
        auto node = qu.top();
        qu.pop();
        for (auto n : ed[node.second])
        {
            if (!vis[get<0>(n)] && get<1>(n))
            {
                vis[get<0>(n)] = true;
                y[get<0>(n)] = node.first + get<2>(n);
                qu.push({y[get<0>(n)], get<0>(n)});
            }
            if (get<1>(n) && y[get<0>(n)] > node.first + get<2>(n))
                y[get<0>(n)] = node.first + get<2>(n);
        }
    }

    vis.clear();
    qu.push(make_pair(0, e));
    vis[e] = true;
    m[e] = 0;

    while (!qu.empty())
    {
        auto node = qu.top();
        qu.pop();
        for (auto n : ed[node.second])
        {
            if (!vis[get<0>(n)] && !get<1>(n))
            {
                vis[get<0>(n)] = true;
                m[get<0>(n)] = node.first + get<2>(n);
                qu.push({m[get<0>(n)], get<0>(n)});
            }
            if (!get<1>(n) && m[get<0>(n)] > node.first + get<2>(n))
                m[get<0>(n)] = node.first + get<2>(n);
        }
    }

    vector<pair<int, char>> vec;
    for (auto node : y)
    {
        if (m.count(node.first))
            vec.push_back({m[node.first] + node.second, node.first});
    }


    sort(vec.begin(), vec.end());
    if (!vec.size())
        cout << "You will never meet." << endl;
    else
    {
        cout << vec[0].first << " " << vec[0].second;
        for (int i{1}; i < vec.size(); ++i)
        {
            if (vec[i].first == vec[i - 1].first)
                cout << " " << vec[i].second; 
            else
                break;
        }
        cout << endl; 
    }
    return false;
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
    while (true)
    {
        if (solve())
            break;
    }
}