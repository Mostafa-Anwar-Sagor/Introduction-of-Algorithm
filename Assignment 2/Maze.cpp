#include <bits/stdc++.h>
using namespace std;
bool valid(int x, int y, int n, int m, vector<string> &m1, vector<vector<bool>> &v)
{
    return x >= 0 && x < n && y >= 0 && y < m && m1[x][y] == '.' && !v[x][y];
}

void solve(int n, int m, vector<string> &ma, vector<vector<bool>> &v)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    v[0][0] = true;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    bool found = false;
    while (!q.empty() && !found)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (ma[x][y] == 'D')
        {
            found = true;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny, n, m, ma, v))
            {
                q.push({nx, ny});
                v[nx][ny] = true;
            }
        }
    }

    if (found)
    {
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (ma[x][y] == '.' && !(x == 0 && y == 0))
            {
                ma[x][y] = 'X';
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (valid(nx, ny, n, m, ma, v))
                {
                    q.push({nx, ny});
                    v[nx][ny] = true;
                }
            }
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<string> maz(n);
    vector<vector<bool>> v(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        cin >> maz[i];
    }
    solve(n, m, maz, v);
    for (int i = 0; i < n; i++)
    {
        cout << maz[i] << endl;
    }
    return 0;
}