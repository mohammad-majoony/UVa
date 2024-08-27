// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499

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

int const N = 2e3 + 5;

void solve()
{
    vector<tuple<int, int, int>> ed;
    int n, m, x, y, w;
    cin >> n >> m;

    for (int i{}; i < m; ++i)
    {
        cin >> x >> y >> w;
        ed.push_back({x, y, w});
    }

    int cost[N];
    bool vis[N];
    cost[0] = 0;
    vis[0] = true;

    for (int i{}; i <= n; ++i)
    {
        for (auto h : ed)
        {
            x = get<0>(h);
            y = get<1>(h);
            w = get<2>(h);

            if (!vis[x])
                continue;

            if (!vis[y])
            {
                vis[y] = true;
                cost[y] = cost[x] + w;
            }
            else if (cost[y] > cost[x] + w)
                cost[y] = cost[x] + w;
        }
    }
    bool res{false};

    for (auto h : ed)
    {
        x = get<0>(h);
        y = get<1>(h);
        w = get<2>(h);

        if (cost[y] > cost[x] + w)
            res = true; 
    }

    cout << ((res) ? "possible" : "not possible") << endl;
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}