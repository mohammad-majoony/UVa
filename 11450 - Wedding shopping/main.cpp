// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-11450

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

int const M = 2e2 + 5, C = 2e1 + 5;
int mem[C][M], m, c, res;
vector<int> garments[C]; 

int dp(int cu, int spend)
{
    if (spend > m)
        return 0;

    if (cu == c)
    {
        if (spend <= m)
            return spend;
        return 0; 
    }

    if (~mem[cu][spend])
        return mem[cu][spend];

    int res{}, re;
    for (auto node: garments[cu])
    {
        re = dp(cu + 1, spend + node); 
        if (re)
            res = max(res, re);
    }
    return mem[cu][spend] = res;
}

void solve()
{
    int l;
    res = -1;
    memset(mem, -1, sizeof mem);
    for (int i{}; i < C; ++i)
        garments[i].clear();

    cin >> m >> c;
    for (int i{}; i < c; ++i)
    {
        cin >> l;
        garments[i].resize(l);
        for (int j{}; j < l; ++j)
            cin >> garments[i][j];
    }

    int res = dp(0, 0);
    if (res)
        cout << res;
    else 
        cout << "no solution";
    cout << endl; 
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
