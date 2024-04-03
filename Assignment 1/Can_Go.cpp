#include <bits/stdc++.h>
using namespace std;

bool jeteparbe(int a, int b, vector<vector<char>> &c, pair<int, int> m, pair<int, int> n)
{
    vector<vector<bool>> v(a, vector<bool>(b, false));
    queue<pair<int, int>> q;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    q.push(m);
    v[m.first][m.second] = true;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        if (curr == n)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int x = curr.first + dx[i];
            int y = curr.second + dy[i];

            if (x >= 0 && x < a && y >= 0 && y < b && c[x][y] != '#' && !v[x][y])
            {
                q.push({x, y});
                v[x][y] = true;
            }
        }
    }

    return false;
}

int main()
{
    int a, b;
    cin >> a >> b;
    vector<vector<char>> c(a, vector<char>(b));
    pair<int, int> m, n;

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 'm')
            {
                m = {i, j};
            }
            else if (c[i][j] == 'n')
            {
                n = {i, j};
            }
        }
    }

    if (jeteparbe(a, b, c, m, n))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
