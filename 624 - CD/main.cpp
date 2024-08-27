// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=565

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

void solve(int we)
{
    int len, num;
    cin >> len;
    vector<int> arr[we + 1];

    for (int i{1}; i <= len; ++i)
    {
        cin >> num;
        for (int i{we}; i > 0; --i)
        {
            if (num > i)
                continue;
            else if (num == i && !arr[i].size())
                arr[i].push_back(num);
            else if (num < i && !arr[i].size() && arr[i - num].size())
            {
                arr[i] = arr[i - num];
                arr[i].push_back(num);
            }
        }
    }

    for (int i{we}; i > 0; --i)
    {
        if (arr[i].size())
        {
            for (auto n: arr[i])
                cout << n << " ";
            cout << "sum:" << i << endl;
            break;
        }
    }
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int we;
    while (cin >> we)
        solve(we);
}