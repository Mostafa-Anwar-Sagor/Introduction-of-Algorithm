#include <bits/stdc++.h>
using namespace std;

bool samecomp(vector<vector<char>> &mat, int s, int js, int d, int jd)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int x[] = {-1, 1, 0, 0};
    int y[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;
    q.push({s, js});
    vis[s][js] = true;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        if (curr.first == d && curr.second == jd)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int p = curr.first + x[i];
            int qq = curr.second + y[i];

            if (p >= 0 && p < n && qq >= 0 && qq < m && mat[p][qq] == '.' && !vis[p][qq])
            {
                q.push({p, qq});
                vis[p][qq] = true;
            }
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    int s, js, d, jd;
    cin >> s >> js >> d >> jd;

    if (samecomp(mat, s, js, d, jd))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
