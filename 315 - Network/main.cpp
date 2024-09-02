// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-315

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
bool vis[N];
int dis[N], low[N], ra, co;
vector<int> ed[N];

void dfs(int cu, int par)
{
    vis[cu] = true;
    dis[cu] = low[cu] = ra++;
    int ch = 0;
    bool art{false};
    for (auto node : ed[cu])
    {
        if (!vis[node])
        {
            dfs(node, cu);
            ch++;
            low[cu] = min(low[cu], low[node]);

            if (par && low[node] >= dis[cu])
                art = true;
        }
        else if (node != par)
        {
            low[cu] = min(low[cu], dis[node]);
        }
    }
    if (!par && ch > 1)
        art = true;
    co += art;
}

bool solve()
{
    int len, x, y, ll;
    cin >> len;
    if (!len)
        return true;

    string txt;
    memset(vis, false, sizeof vis);
    for (int i{}; i <= len; ++i)
        ed[i].clear();
    ra = 1;
    co = 0;

    cin.ignore();
    while (getline(cin, txt))
    {
        if (txt.size() == 1 && txt == "0")
            break;

        vector<int> sp;
        for (int i{}; i < txt.size(); ++i)
            if (txt[i] == ' ')
                sp.push_back(i);

        ll = sp.size();
        x = stoll(txt.substr(0, sp[0]));
        for (int i{1}; i < ll; ++i)
        {
            y = stoll(txt.substr(sp[i - 1] + 1, sp[i] - sp[i - 1] - 1));
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        y = stoll(txt.substr(sp[ll - 1] + 1, txt.size() - sp[ll - 1] - 1));
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    dfs(1, 0);
    cout << co << endl;
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
        if (solve())
            break;
}