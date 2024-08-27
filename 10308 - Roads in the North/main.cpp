// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-10308

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

int const N = 1e4 + 5;
int maxi;
vector<pair<int, int>> ed[N];
int mem[N];

int dfs1(int cu, int par)
{
    int res{0};
    for (auto node : ed[cu])
    {
        if (node.first == par)
            continue;
        res = max(res, dfs1(node.first, cu) + node.second);
    }
    return mem[cu] = res;
}

void dfs2(int cu, int par, int top)
{
    vector<int> d = {top, 0};
    for (auto node : ed[cu])
    {
        if (node.first == par)
            continue;
        d.push_back(mem[node.first] + node.second);
    }

    sort(d.rbegin(), d.rend());

    maxi = max(maxi, d[0] + d[1]);

    for (auto node : ed[cu])
    {
        if (node.first == par)
            continue;

        if (mem[node.first] + node.second == d[0])
            dfs2(node.first, cu, d[1] + node.second);
        else
            dfs2(node.first, cu, d[0] + node.second);
    }
}

bool solve()
{
    bool res{true};
    maxi = 0;
    memset(mem, -1, sizeof mem);
    for (int i{}; i < N; ++i)
        ed[i].clear();

    int x, y, a;
    string txt;
    while (true)
    {
        vector<int> sp;
        getline(cin, txt);
        if (txt.empty())
            break;
        for (int i{1}; i < txt.size(); ++i)
            if (txt[i] == ' ')
                sp.push_back(i);

        x = stoll(txt.substr(0, sp[0])); 
        y = stoll(txt.substr(sp[0] + 1, sp[1] - sp[0] - 1)); 
        a = stoll(txt.substr(sp[1])); 

        res = false;
        ed[x].push_back({y, a});
        ed[y].push_back({x, a});
    }
    if (res)
        return res;

    dfs1(1, 0);
    dfs2(1, 0, 0);

    cout << maxi << endl;
    return res;
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int tc;
    // cin >> tc;
    while (true)
    {
        if (solve())
            break;
    }
}