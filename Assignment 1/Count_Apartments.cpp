#include <bits/stdc++.h>
using namespace std;

void apartment(int a, int b, int c, int m, vector<vector<char>> &v, vector<vector<bool>> &s)
{
    if (a < 0 || a >= c || b < 0 || b >= m || v[a][b] == '#' || s[a][b])
    {
        return;
    }
    s[a][b] = true;
    apartment(a - 1, b, c, m, v, s);
    apartment(a + 1, b, c, m, v, s);
    apartment(a, b - 1, c, m, v, s);
    apartment(a, b + 1, c, m, v, s);
}

int cntaprt(int a, int b, vector<vector<char>> &v)
{
    vector<vector<bool>> s(a, vector<bool>(b, false));
    int cnt = 0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (v[i][j] == '.' && !s[i][j])
            {
                cnt++;
                apartment(i, j, a, b, v, s);
            }
        }
    }
    return cnt;
}

int main()
{
    int c, m;
    cin >> c >> m;
    vector<vector<char>> v(c, vector<char>(m));

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << cntaprt(c, m, v) << endl;
    return 0;
}
