// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-11367#author=0

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

void solve()
{
    int n, m, x, y, dis, q, ca;
    cin >> n >> m;
    int gas[n];
    for (int i{}; i < n; ++i)
        cin >> gas[i];

    vector<pair<int, int>> ed[n];

    for (int i{}; i < m; ++i)
    {
        cin >> x >> y >> dis;
        ed[x].push_back({y, dis});
        ed[y].push_back({x, dis});
    }

    cin >> q;
    while (q--)
    {
        cin >> ca >> x >> y;
        int cost[n][ca + 1], mini = LLONG_MAX;
        memset(cost, -1, sizeof cost);
        priority_queue<tu, vector<tu>, greater<tu>> qu;
        qu.push({0, x, 0});
        cost[x][0] = 0;

        while (!qu.empty())
        {
            auto [co, node, cap] = qu.top();
            qu.pop();
            if (node == y)
                mini =  min(mini, co);

            if (cost[node][cap] < co)
                continue;

            if (cap < ca)
            {
                if (cost[node][cap + 1] == -1 || cost[node][cap + 1] > cost[node][cap] + gas[node])
                {
                    cost[node][cap + 1] = cost[node][cap] + gas[node];
                    qu.push({cost[node][cap + 1], node, cap + 1});
                }
            }

            for (auto n : ed[node])
            {
                auto [way, d] = n;
                if (cap >= d)
                {
                    if (cost[way][cap - d] == -1 || cost[way][cap - d] > cost[node][cap])
                    {
                        cost[way][cap - d] = cost[node][cap];
                        qu.push({cost[way][cap - d], way, cap - d});
                    }
                }
            }
        }

        if (mini == LLONG_MAX)
            cout << "impossible" << endl;
        else
            cout << mini << endl;
    }
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    // int tc ; cin >> tc; while(tc--)
    solve();
}