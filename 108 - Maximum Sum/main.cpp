// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-108

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

void solve()
{
    int len, num, add, maxi{LLONG_MIN};
    cin >> len;
    int dp[len + 1][len + 1];
    memset(dp, 0, sizeof dp);
    for (int i{1}; i <= len; ++i)
    {
        add = 0;
        for (int j{1}; j <= len; ++j)
        {
            cin >> num;
            add += num; 
            dp[i][j] = add + dp[i - 1][j];
        }
    }

    for (int i{1}; i <= len; ++i)
    {
        for (int j{1}; j <= len; ++j)
        {
            for (int k{}; k < i; ++k)
            {
                for (int l{}; l < j; ++l)
                {
                    maxi = max(maxi, dp[i][j] - dp[k][l] - (dp[i][l] - dp[k][l]) - (dp[k][j] - dp[k][l]));
                }
            }
        }
    }

    cout << maxi << endl;
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