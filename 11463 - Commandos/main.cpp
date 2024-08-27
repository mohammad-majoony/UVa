// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-11463

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

int solve()
{
    int n, m, x, y, s, e, t, maxi = 0;

    cin >> n >> m;
    int toS[n], toE[n];
    vector<int> ed[n];    

    bool vis[n]{false};

    for (int i{}; i < m; ++i)
    {
        cin >> x >> y;
        ed[x].push_back(y); 
        ed[y].push_back(x); 
    } 
    cin >> s >> e;

    queue<int> qu; 

    qu.push(s);
    vis[s] = true;
    toS[s] = 0;
    while (!qu.empty())
    {
        t = qu.front();
        qu.pop();
        for (auto node: ed[t])
        {
            if (!vis[node])
            {
                qu.push(node);
                vis[node] = true;
                toS[node] = 1 + toS[t];
            }
        }
    }

    memset(vis, false, sizeof vis);
    qu.push(e);
    toE[e] = 0;
    vis[e] = true;
    while (!qu.empty())
    {
        t = qu.front();
        qu.pop();
        for (auto node: ed[t])
        {
            if (!vis[node])
            {
                qu.push(node);
                vis[node] = true;
                toE[node] = 1 + toE[t];
            }
        }
    }

    for (int i{}; i < n; ++i)
        maxi = max(maxi, toS[i] + toE[i]);
    return maxi;
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
    for (int i{1}; i <= tc; ++i)
        cout << "Case " << i << ": " << solve() << endl;;
}