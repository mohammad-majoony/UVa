// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-336

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

int tc{};
bool solve()
{
    map<int, vector<int>> ed;
    int len, x, y;
    cin >> len;
    if (!len)
        return true;

    for (int i{}; i < len; ++i) 
    {
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    queue<pair<int, int>> qu;
    map<int, bool> vis;
    int visCount, node, ttl;

    while (true)
    {
        cin >> x >> y;
        if (!x && !y)
            break;

        qu.push({x, y});
        vis[x] = true;
        visCount = 0;
        while (!qu.empty())
        {
            visCount++;
            node = qu.front().first;
            ttl = qu.front().second;
            qu.pop();
            if (!ttl)
                continue; 
            for (auto nei: ed[node])
            {
                if (!vis[nei])
                {
                    vis[nei] = true;
                    qu.push({nei, ttl - 1});
                }
            }
        }
        cout << "Case " << ++tc << ": " << ed.size() - visCount << " nodes not reachable from node " << x << " with TTL = " << y << "." << endl; 
        vis.clear();
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
    // cin >> tc;
    while (true)
        if (solve())
            break;
}