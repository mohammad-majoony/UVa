// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-902

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

int const charCount = 26;
struct Trie
{
    struct Node
    {
        Node *next[charCount];
        bool endWord{false};
        int count{};
        Node()
        {
            for (int i{}; i < charCount; ++i)
                this->next[i] = NULL;
        }
    };

    Node *root;
    Trie()
    {
        this->root = new Node;
    }

    void insertWord(deque<char> &dq)
    {
        int charInd, len = dq.size(), maxi{};
        Node *cu = root;
        vector<Node *> vec;

        for (int i{}; i < len; ++i)
        {
            charInd = dq[i] - 'a';
            if (cu->next[charInd] == NULL)
                cu->next[charInd] = new Node;
            cu = cu->next[charInd];
            if (i == len - 1)
            {
                cu->count++;
                maxi = cu->count;
            }
            vec.push_back(cu);
        }
        for (auto n : vec)
            n->count = max(n->count, maxi);

        cu->endWord = true;
    }

    string mostOften()
    {
        Node *cu = root;
        string txt;
        int maxiInd, maxi;
        for (int i{};; ++i)
        {
            maxi = 0;
            for (int j{}; j < charCount; ++j)
            {
                if (cu->next[j] == NULL)
                    continue;

                if (cu->next[j]->count > maxi)
                {
                    maxi = cu->next[j]->count;
                    maxiInd = j;
                }
            }
            if (!maxi)
                break;
            txt += 'a' + maxiInd;
            cu = cu->next[maxiInd];
        }
        return txt;
    }
};

void solve(int k, string txt)
{
    Trie t;
    int len;
    len = txt.size();

    deque<char> dq;
    for (int i{}; i < k; ++i)
        dq.push_back(txt[i]);

    for (int i{k}; i < len; ++i)
    {
        t.insertWord(dq);
        dq.pop_front();
        dq.push_back(txt[i]);
    }
    t.insertWord(dq);

    cout << t.mostOften() << endl;
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int k;
    string txt;
    while (cin >> k >> txt)
        solve(k, txt);
}