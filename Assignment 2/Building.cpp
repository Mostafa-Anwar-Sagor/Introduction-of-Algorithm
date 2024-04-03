#include <bits/stdc++.h>
using namespace std;

class Building
{
public:
    vector<int> p, r;

    Building(int n)
    {
        p.resize(n + 1);
        r.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
        }
    }

    int fset(int v)
    {
        if (v == p[v])
        {
            return v;
        }
        return p[v] = fset(p[v]);
    }

    void uset(int a, int b)
    {
        a = fset(a);
        b = fset(b);
        if (a != b)
        {
            if (r[a] < r[b])
            {
                swap(a, b);
            }
            p[b] = a;
            if (r[a] == r[b])
            {
                r[a]++;
            }
        }
    }
};

int khoroch(int n, vector<pair<int, pair<int, int>>> &e)
{
    sort(e.begin(), e.end());
    Building b(n);
    int tottal = 0;
    int comp = 0;

    for (auto &ed : e)
    {
        int u = ed.second.first;
        int v = ed.second.second;
        if (b.fset(u) != b.fset(v))
        {
            b.uset(u, v);
            tottal += ed.first;
            comp++;
        }
    }

    if (comp == n - 1)
    {
        return tottal;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> e(m);

    for (int i = 0; i < m; i++)
    {
        cin >> e[i].second.first >> e[i].second.second >> e[i].first;
    }

    int folafol = khoroch(n, e);
    cout << folafol << endl;
    return 0;
}
