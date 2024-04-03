#include <bits/stdc++.h>
using namespace std;

class cycle
{
public:
    vector<int> p, r;

    cycle(int n)
    {
        p.resize(n + 1);
        r.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
        }
    }

    int setkhujo(int v)
    {
        if (v == p[v])
        {
            return v;
        }
        return p[v] = setkhujo(p[v]);
    }

    void uset(int a, int b, int &c)
    {
        a = setkhujo(a);
        b = setkhujo(b);
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
        else
        {
            c++;
        }
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    cycle cf(n);
    int c = 0;
    for (int i = 0; i < e; i++)
    {
        int p, q;
        cin >> p >> q;
        cf.uset(p, q, c);
    }
    cout << c << endl;

    return 0;
}
