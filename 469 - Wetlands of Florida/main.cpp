// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-469

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

vector<string> arr;
map<pair<int, int>, pair<int, int>> fa;
map<pair<int, int>, int> r;

int dfs(int i, int j, pair<int, int> f)
{
    arr[i][j] = 'L';

    if (f.first == -1 && f.second == -1)
        f = {i, j}; 
    fa[{i, j}] = f;

    int res{1}, ii, jj;
    int p1[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int p2[] = {1, 1, 0, -1, -1, -1, 0, 1};

    for (int k{}; k < 8; ++k)
    {
        ii = p1[k] + i, jj = p2[k] + j;
        if (ii >= 0 && ii < arr.size() && jj >= 0 && jj < arr[i].size() && arr[ii][jj] == 'W')
            res += dfs(ii, jj, f);
    }
    return r[{i, j}] = res;
}

int result(int i, int j)
{
    i--, j--;
    if (fa.count({i, j}))
        return r[fa[{i, j}]];
    return 0;
}

void solve()
{
    arr.clear();
    fa.clear();
    string t;
    while (true)
    {
        getline(cin, t);
        if (t[0] != 'L' && t[0] != 'W')
            break;
        arr.push_back(t);
    }

    for (int i{}; i < arr.size(); ++i)
    {
        for (int j{}; j < arr[i].size(); ++j)
        {
            if (arr[i][j] == 'W')
                dfs(i, j, make_pair(-1, -1));
        }
    }

    while (true)
    {
        vector<int> sp;
        for (int i{}; i < t.size(); ++i)
            if (t[i] == ' ')
                sp.push_back(i);
        cout << result(stoll(t.substr(0, sp[0])), stoll(t.substr(sp[0] + 1))) << endl;
        getline(cin, t);
        if (!t.size())
            break;
    }
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string bl;
    int tc;
    cin >> tc;
    cin.ignore();
    getline(cin, bl);
    while (tc--)
    {
        solve();
        if (tc)
            cout << endl;        
    }
}