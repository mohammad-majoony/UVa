// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://vjudge.net/problem/UVA-820

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

struct Dinic
{
    struct Edge
    {
        int v1, v2, flow;
        // v1 to v2 with flow
        Edge(int v1, int v2, int cap)
        {
            this->v1 = v1;
            this->v2 = v2;
            this->flow = cap;
        }
    };

    vector<vector<int>> edgeNum;
    vector<Edge> edges;
    vector<int> level;
    vector<int> edge_count;
    int len, source, sink, ec{};

    Dinic(int len, int source, int sink)
    {
        this->source = source;
        this->sink = sink;
        this->len = len;
        edgeNum.resize(len + 1);
        edge_count.resize(len + 1);
    }

    void add_edge(int v1, int v2, int cap)
    {
        edges.push_back({v1, v2, cap}); // forward edge
        edges.push_back({v2, v1, cap}); // backward edge
        // edgeNum[x] store the number of edges for node x
        edgeNum[v1].push_back(ec++); // forward edge is i and is even,
        edgeNum[v2].push_back(ec++); // backward edge is i + 1 and is odd
    }

    bool level_edgeNumaph()
    {
        level.clear();
        level.resize(len + 1, -1);

        queue<int> qu;
        qu.push(source);
        level[source] = 0;
        while (!qu.empty())
        {
            int v1 = qu.front();
            qu.pop();

            for (auto edgeNumber : edgeNum[v1])
            {
                int v2 = edges[edgeNumber].v2;
                int flow = edges[edgeNumber].flow;

                if (flow && level[v2] == -1)
                {
                    level[v2] = level[v1] + 1;
                    qu.push(v2);
                }
            }
        }

        return level[this->sink] != -1;
    }

    int agument(int cu, int bottleneckVal = 1e15)
    {
        if (cu == sink)
            return bottleneckVal;

        for (int &i = edge_count[cu]; i >= 0; i--)
        {
            int bottleneck_flow{};
            int edge_index = edgeNum[cu][i];
            int flow = edges[edge_index].flow;
            int v2 = edges[edge_index].v2;

            if (flow && level[v2] == level[cu] + 1)
                bottleneck_flow = agument(v2, min(flow, bottleneckVal));
            if (bottleneck_flow)
            {
                edges[edge_index].flow -= bottleneck_flow;
                edges[edge_index ^ 1].flow -= bottleneck_flow;
                return bottleneck_flow;
            }
        }
        return 0;
    }

    int max_flow()
    {
        int total_flow{};

        while (level_edgeNumaph())
        {

            // while find a argumenting path
            for (int i = 0; i <= len; i++)
                edge_count[i] = edgeNum[i].size() - 1;
            while (int flow = agument(this->source))
                total_flow += flow;
        }

        return total_flow;
    }
};

bool solve(int tc)
{
    int n, s, e, m, x, y, w;
    cin >> n;
    if (!n)
        return false;
    cin >> s >> e >> m;

    Dinic d = Dinic(n, s, e);
    for (int i{}; i < m; ++i)
    {
        cin >> x >> y >> w;
        d.add_edge(x, y, w);
    }

    //  cout <<  d.max_flow() << endl;
    cout << "Network " << tc << endl;;
    cout << "The bandwidth is " << d.max_flow() << "." << endl << endl;

    return true;
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int tc{1};
    // cin >> tc;
    while (solve(tc++))
        true;
}