#include <bits/stdc++.h>
using namespace std;

int adventure(int w, int t[], int v[], int n)
{
    int p[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            if (i == 0 || wt == 0)
            {
                p[i][wt] = 0;
            }
            else if (t[i - 1] <= wt)
            {
                p[i][wt] = max(v[i - 1] + p[i - 1][wt - t[i - 1]], p[i - 1][wt]);
            }
            else
            {
                p[i][wt] = p[i - 1][wt];
            }
        }
    }
    return p[n][w];
}

int main()
{
    int m;
    cin >> m;

    while (m--)
    {
        int o, W;
        cin >> o >> W;
        int t[o], v[o];
        for (int i = 0; i < o; i++)
        {
            cin >> t[i];
        }
        for (int i = 0; i < o; i++)
        {
            cin >> v[i];
        }
        int rslt = adventure(W, t, v, o);
        cout << rslt << endl;
    }
    return 0;
}
