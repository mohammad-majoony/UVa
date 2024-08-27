// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-821

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MAJOONI ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define int long long
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> c_set;

double res;
int const N = 1e2 + 5;
bool solve()
{
    map<int, int> nums;
    int x, y, num{};
    cin >> x >> y;
    if (!x && !y)
        return true;

    vector<int> ed[N];
    int dp[N][N];
    for (int i{}; i < N; ++i)
    {
        for (int j{}; j < N; ++j)
            dp[i][j] = N + N;
        dp[i][i] = 0;
    }

    while (true)
    {
        if (!nums.count(x))
            nums[x] = num++;
        if (!nums.count(y))
            nums[y] = num++;

        x = nums[x];
        y = nums[y];

        ed[x].push_back(y);
        dp[x][y] = 1;

        cin >> x >> y;
        if (!x && !y)
            break;
    }

    for (int k{}; k < num; ++k)
        for (int i{}; i < num; ++i)
            for (int j{}; j < num; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    int sums{};
    for (int i{}; i < num; ++i)
        for (int j{}; j < num; ++j)
            sums += dp[i][j];

    res = sums * 1.0 / (num * (num - 1));
    return false;
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int tc{1};
    // cin >> tc;
    while (true)
    {
        if (solve())
            break;
        cout << fixed << setprecision(3) << "Case " << tc++ << ": average length between pages = " << res << " clicks" << endl;
    }
}