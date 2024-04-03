#include <bits/stdc++.h>
using namespace std;
class sortest
{
public:
    int d;
    long long w;
};

bool distance(vector<vector<sortest>> &g, int s, int m, vector<long long> &di)
{
    auto tulona = [](pair<int, long long> &a, pair<int, long long> &b)
    {
        return a.second > b.second;
    };

    priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(tulona)> pq(tulona);
    pq.push({s, 0});

    while (!pq.empty())
    {
        pair<int, long long> curr = pq.top();
        pq.pop();

        int u = curr.first;
        long long cw = curr.second;

        if (u == m)
        {
            return true;
        }

        for (sortest &edge : g[u])
        {
            int v = edge.d;
            long long ed = edge.w;

            if (di[u] + ed < di[v])
            {
                di[v] = di[u] + ed;
                pq.push({v, di[v]});
            }
        }
    }

    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<sortest>> g(n + 1);
    for (int i = 0; i < e; ++i)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        vector<long long> di(n + 1, LLONG_MAX);
        di[x] = 0;

        if (distance(g, x, y, di))
        {
            cout << min(di[y], LLONG_MAX) << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}
