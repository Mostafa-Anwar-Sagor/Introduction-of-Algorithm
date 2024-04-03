#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> v;

int area(int i, int j, int n, int m, vector<string> &matt)
{
    if (i < 0 || i >= n || j < 0 || j >= m || matt[i][j] == '-' || v[i][j])
    {
        return 0;
    }

    v[i][j] = true;
    int a = 1;
    a += area(i + 1, j, n, m, matt);
    a += area(i - 1, j, n, m, matt);
    a += area(i, j + 1, n, m, matt);
    a += area(i, j - 1, n, m, matt);

    return a;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> matt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> matt[i];
    }

    v.assign(n, vector<bool>(m, false));
    int s = INT_MAX;
    bool comp = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matt[i][j] == '.' && !v[i][j])
            {
                comp = true;
                int a = area(i, j, n, m, matt);
                s = min(s, a);
            }
        }
    }

    if (!comp)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << s << endl;
    }

    return 0;
}
