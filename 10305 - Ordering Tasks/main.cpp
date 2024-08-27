// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-10305

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
bool vis[N];
stack<int> st;

void dfs(int cu)
{
    vis[cu] = true;
    for (auto n : ed[cu])
    {
        if (!vis[n])
            dfs(n);
    }
    st.push(cu);
}

bool solve()
{
    memset(vis, false, sizeof vis);
    int n, m, x, y;
    cin >> n >> m;
    if (!n && !m)
        return true;

    for (int i{}; i < m; ++i)
    {
        cin >> x >> y;
        ed[x].push_back(y);
    }

    for (int i{1}; i <= n; ++i)
    {
        if (!vis[i])
            dfs(i);
    }

    int prCount{};
    while (!st.empty())
    {
        prCount++;
        if (prCount == n)
            cout << st.top() << endl;
        else 
            cout << st.top() << " ";
        st.pop();
    }

    return false;
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