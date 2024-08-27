// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-10364

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

int const N = 2e1;
vector<int> nums;
int mem[1 << N];
int di;

int dp(int mask, int mod)
{
    if (!mask)
    {
        if (mod)
            return false;
        return true;
    }
    if (~mem[mask])
        return mem[mask];
    for (int i{}; i < N; ++i)
    {
        if (((mask >> i) & 1) && mod + nums[i] <= di)
            if (dp(mask ^ (1 << i), (mod + nums[i]) % di))
                return mem[mask] = true;
    }
    return mem[mask] = false;
}

string solve()
{
    memset(mem, -1, sizeof mem);
    nums.clear();
    int len, sums{};
    cin >> len;
    nums.resize(len);
    for (int i{}; i < len; ++i)
    {
        cin >> nums[i];
        sums += nums[i];
    }
    if (sums % 4)
        return "no"; 
    di = sums / 4;
    return ((dp((1 << len) - 1, 0)) ? "yes" : "no"); 
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
        cout << solve() << endl;
}