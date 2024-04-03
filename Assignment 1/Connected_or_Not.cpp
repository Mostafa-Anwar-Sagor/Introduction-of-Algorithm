#include <bits/stdc++.h>
using namespace std;
int main()
{

    int a, b, c;
    cin >> a >> b;
    vector<vector<int>> graph(a, vector<int>(a, 0));
    for (int i = 0; i < b; i++)
    {
        int m, n;
        cin >> m >> n;
        graph[m][n] = 1;
    }
    cin >> c;
    while (c--)
    {
        int p, q;
        cin >> p >> q;
        if (p == q || graph[p][q] == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}