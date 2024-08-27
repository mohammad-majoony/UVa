// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-11631

#include <bits/stdc++.h>
#define MAJOONI ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define endl '\n'
#define int long long
using namespace std;

int len, e;
map<int, vector<pair<int, int>>> edge;

int MST()
{
    bool vis[len + 1]{0};
    int visCount = 0, res = 0, f, s, node;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
    qu.push(make_pair(0, 0));

    while (visCount != len)
    {
        visCount++;
        while (true)
        {
            f = qu.top().first;
            s = qu.top().second;
            if (!vis[s])
            {
                res += f;
                vis[s] = true;
                qu.pop();
                break;
            }
            else
                qu.pop();
        }
        for (auto p : edge[s])
            qu.push(p);
    }
    return res;
}

bool solve()
{
    int x, y, w, sums{};
    edge.clear();
    cin >> len >> e;
    if (!len && !e)
        return true;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> w;
        edge[x].push_back(make_pair(w, y));
        edge[y].push_back(make_pair(w, x));
        sums += w;
    }
    cout << sums - MST() << endl;
    return false;
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc;
    // cin >> tc;
    while (true)
    {
        bool res = solve();
        if (res)
            break;
    }
}