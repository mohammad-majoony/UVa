// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-10000

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

int const N = 1e2 + 5;
vector<int> ed[N];
pair<int, int> mem[N];
int maxi, en;

pair<int, int> dfs(int cu)
{
    // first == dep, second == end
    if (~mem[cu].first && ~mem[cu].second)
        return mem[cu];

    pair<int, int> res = {0, cu};
    for (auto n : ed[cu])
    {
        auto g = dfs(n);
        if (g.first > res.first || (g.first == res.first && g.second < res.second))
            res = g;  
    }
    res.first++;
    return mem[cu] = res;
}


bool solve(int tc)
{
    for (int i{}; i < N; ++i)
    {
        mem[i] = {-1, -1};
        ed[i].clear();
    }
    maxi = 0;

    int len, x, y, s;
    cin >> len;

    if (!len)
        return false;
    
    cin >> s;
    while (true)
    {
        cin >> x >> y;
        if (!x && !y)
            break;
        ed[x].push_back(y); 
    }
    auto r = dfs(s);
    cout << "Case " << tc << ": The longest path from " << s << " has length " << --r.first << ", finishing at " << r.second << "." << endl;
    cout << endl;

    return true;
}

int32_t main()
{
    // MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int tc{1};
    // cin >> tc;
    while (solve(tc++))
        true;
}