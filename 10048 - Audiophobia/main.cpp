// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-10048#author=0

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

bool solve(int tc)
{
    int n, m, q, x, y, dis;
    cin >> n >> m >> q;

    if (!n && !m && !q)
        return false;

    if (tc != 1)
        cout << endl;

    int dp[n][n];
    memset(dp, -1, sizeof dp);
    for (int i{}; i < n; ++i)
        dp[i][i] = 0;

    for (int i{}; i < m; ++i)
    {
        cin >> x >> y >> dis;
        x--, y--;
        dp[x][y] = dis;
        dp[y][x] = dis;
    }

    for (int k{}; k < n; ++k)
    {
        for (int i{}; i < n; ++i)
        {
            for (int j{}; j < n; ++j)
            {
                if (~dp[i][k] && ~dp[k][j])
                {
                    if (!~dp[i][j])
                        dp[i][j] = max(dp[i][k], dp[k][j]);
                    else
                        dp[i][j] = min({dp[i][j], max(dp[i][k], dp[k][j])});
                }
            }
        }
    }

    cout << "Case #" << tc << endl;
    while (q--)
    {
        cin >> x >> y;
        x--, y--;
        if (~dp[x][y])
            cout << dp[x][y] << endl;
        else
            cout << "no path" << endl;
    }

    return true;
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int tc{1};
    while (solve(tc++))
        true;
}