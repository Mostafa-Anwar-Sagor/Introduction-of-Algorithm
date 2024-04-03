#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int s, d;
    long long w;
};

bool cangoagain(vector<Edge> &ed, int n, int e, int c, vector<long long> &d)
{
    d[c] = 0;

    for (int i = 1; i <= n - 1; ++i)
    {
        for (const auto &edge : ed)
        {
            int u = edge.s;
            int v = edge.d;
            long long w = edge.w;

            if (d[u] != LLONG_MAX && d[u] + w < d[v])
            {
                d[v] = d[u] + w;
            }
        }
    }

    for (const auto &edge : ed)
    {
        int u = edge.s;
        int v = edge.d;
        long long w = edge.w;

        if (d[u] != LLONG_MAX && d[u] + w < d[v])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edges(e);
    for (int i = 0; i < e; ++i)
    {
        cin >> edges[i].s >> edges[i].d >> edges[i].w;
    }

    int c;
    cin >> c;

    int t;
    cin >> t;

    vector<long long> dis(n + 1, LLONG_MAX);

    if (cangoagain(edges, n, e, c, dis))
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    while (t--)
    {
        int p;
        cin >> p;

        if (dis[p] == LLONG_MAX)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dis[p] << endl;
        }
    }

    return 0;
}
