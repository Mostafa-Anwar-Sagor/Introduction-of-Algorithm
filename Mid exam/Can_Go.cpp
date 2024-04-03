#include <bits/stdc++.h>
using namespace std;

void cango(vector<pair<int, long long>> g[], int s, vector<long long> &d)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({0, s});

    while (!q.empty())
    {
        long long curr = q.top().first;
        int u = q.top().second;
        q.pop();

        if (d[u] < curr)
        {
            continue;
        }

        for (auto e : g[u])
        {
            int v = e.first;
            long long w = e.second;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, long long>> g[n + 1];

    for (int i = 0; i < e; i++)
    {
        int a, b;
        long long x;
        cin >> a >> b >> x;
        g[a].push_back({b, x});
    }

    int y;
    cin >> y;

    int m;
    cin >> m;

    while (m--)
    {
        int c;
        long long yy;
        cin >> c >> yy;

        vector<long long> d(n + 1, LLONG_MAX);
        d[y] = 0;
        cango(g, y, d);

        if (d[c] <= yy)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
