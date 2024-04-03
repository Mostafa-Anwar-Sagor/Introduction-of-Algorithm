#include <bits/stdc++.h>
using namespace std;

class ufind
{
public:
    vector<int> p, r;

    ufind(int n)
    {
        p.resize(n + 1);
        r.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            p[i] = i;
    }

    int fset(int v)
    {
        if (v == p[v])
            return v;
        return p[v] = fset(p[v]);
    }

    void uset(int a, int b)
    {
        a = fset(a);
        b = fset(b);
        if (a != b)
        {
            if (r[a] < r[b])
                swap(a, b);
            p[b] = a;
            if (r[a] == r[b])
                r[a]++;
        }
    }
};

pair<int, int> Cost(int n, vector<pair<pair<int, int>, int>> &e)
{
    sort(e.begin(), e.end(), [](auto &a, auto &b)
         { return a.second < b.second; });

    ufind uf(n);
    int totalCost = 0;
    int adges = 0;

    for (auto &edge : e)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;

        if (uf.fset(u) != uf.fset(v))
        {
            uf.uset(u, v);
            totalCost += w;
            adges++;

            if (adges == n - 1)
            {
                break;
            }
        }
    }

    if (adges != n - 1)
    {
        return {adges, -1};
    }

    return {adges, totalCost};
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<pair<int, int>, int>> ed(e);
    for (int i = 0; i < e; ++i)
    {
        cin >> ed[i].first.first >> ed[i].first.second >> ed[i].second;
    }

    pair<int, int> result = Cost(n, ed);

    if (result.second == -1)
    {
        cout << "Not Possible" << endl;
    }
    else
    {
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
