// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-10911

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

int const N = 16;
vector<pair<int, int>> po;
double mem[1 << N];

double dp(int mask)
{
    if (!mask)
        return 0;
    if (mem[mask])
        return mem[mask];

    double res = 1.0 + 100000000000, add;
    for (int i{}; i < N; ++i)
    {
        for (int j{i + 1}; j < N; ++j)
        {
            if (((mask >> i) & 1) && ((mask >> j) & 1))
            {
                add = sqrt((pow(po[i].first - po[j].first, 2) + pow(po[i].second - po[j].second, 2)));
                res = min(res, dp(mask ^ (1 << i) ^ (1 << j)) + add);
            }
        }
    }
    return mem[mask] = res;
}

bool solve(int tc)
{
    int len;
    cin >> len;
    if (!len)
        return true;

    po.clear();
    memset(mem, 0, sizeof mem);

    string txt;
    cin.ignore();
    len *= 2;
    for (int i{}; i < len; ++i)
    {
        vector<int> spec;
        getline(cin, txt);
        for (int i{}; i < txt.size(); ++i)
            if (txt[i] == ' ')
                spec.push_back(i);
        po.push_back(make_pair(stol(txt.substr(spec[0] + 1, spec[1] - 1)), stol(txt.substr(spec[1] + 1))));
    }

    cout << fixed << setprecision(2) << "Case " << tc << ": " << dp((1 << len) - 1) << endl;

    return false;
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int tc{};
    // cin >> tc;
    while (true)
    {
        tc++;
        if (solve(tc))
            break;
    }
}