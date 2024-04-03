#include <bits/stdc++.h>
using namespace std;
class moves
{
public:
    int i, j, s;
};

int knight_moves(int n, int m, int ki, int kj, int qi, int qj)
{
    vector<vector<bool>> v(n, vector<bool>(m, false));
    vector<int> di = {-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> dj = {1, 2, 2, 1, -1, -2, -2, -1};

    queue<moves> q;
    q.push({ki, kj, 0});
    v[ki][kj] = true;

    while (!q.empty())
    {
        moves curr = q.front();
        q.pop();

        if (curr.i == qi && curr.j == qj)
        {
            return curr.s;
        }

        for (int k = 0; k < 8; k++)
        {
            int ni = curr.i + di[k];
            int nj = curr.j + dj[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !v[ni][nj])
            {
                v[ni][nj] = true;
                q.push({ni, nj, curr.s + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, ki, kj, qi, qj;
        cin >> n >> m >> ki >> kj >> qi >> qj;

        int folafol = knight_moves(n, m, ki, kj, qi, qj);
        cout << folafol << endl;
    }

    return 0;
}
