// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-10938

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

int const N = 5e3 + 5;
vector<int> ed[N];

vector<int> pos, pr;
void dfs(int cu, int par, int end)
{
    pos.push_back(cu);

    if (cu == end)
    {
        int len = pos.size();
        if (pos.size() % 2)
            pr.push_back(pos[len / 2]);
        else 
        {
            pr.push_back(pos[len / 2]);
            pr.push_back(pos[len / 2 - 1]);
        }
    }

    for (auto n : ed[cu])
    {
        if (n == par)
            continue;
        dfs(n, cu, end); 
    }
    pos.pop_back();
}


bool solve()
{
    int len, x, y, q;
    cin >> len;
    if (!len)
        return false;

    for (int i{}; i <= len; ++i)
        ed[i].clear(); 

    for (int i{1}; i < len; ++i)
    {
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    cin >> q;
    while(q--)
    {
        pos.clear();
        pr.clear();
        cin >> x >> y;
        dfs(x, -1, y);
        sort(pr.begin(), pr.end());
        
        if (pr.size() == 1)
            cout << "The fleas meet at " << pr[0] << "." << endl;
        else    
            cout << "The fleas jump forever between " << pr[0] << " and " << pr[1] << "." << endl; 

    }

    return true;
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int tc ;
    // cin >> tc;
    while(solve())
        true;
}