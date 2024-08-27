// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-543

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

int const N = 1e6 + 5;
bool flag[N]{false};
vector<int> primes;

void findPrimes()
{
    for (int i{2}; i < N; ++i)
    {
        if (flag[i])
            continue;
        primes.push_back(i);
        for (int j{i * i}; j < N; j += i)
            flag[j] = true;
    }
}

bool solve()
{
    int num;
    cin >> num;
    if (!num)
        return true;

    for (int i{1}; i < primes.size() && primes[i] < num && num % 2 == 0; ++i)
    {
        if (!flag[num - primes[i]])
        {
            cout << num << " = " << primes[i] << " + " << num - primes[i] << endl;
            return false;
        }
    }
    cout << "Goldbach's conjecture is wrong." << endl;
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
    findPrimes();
    // cin >> tc;
    while (true)
        if (solve())
            break;
}