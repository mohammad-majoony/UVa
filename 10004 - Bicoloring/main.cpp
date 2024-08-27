// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-10004 

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

int const N = 2e2 + 5;

bool solve()
{
    int n, m, no, x, y;
    cin >> n; 
    if (!n)
        return true;
    cin >> m;

    vector<int> ed[N];
    for (int i{}; i < m; ++i)
    {
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    queue<int> qu;
    int vis[N]{};
    vis[0] = 1;
    qu.push(0);
    bool res{true};
    while (!qu.empty())
    {
        no = qu.front();
        qu.pop();
        for (auto nei : ed[no])
        {
            if (!vis[nei])
            {
                qu.push(nei);
                vis[nei] = (vis[no] == 1) ? 2 : 1; 
            }
            else if (vis[nei] == vis[no])
            {
                res = false;
                break;
            }   
        }
    }
    cout << ((res) ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;

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