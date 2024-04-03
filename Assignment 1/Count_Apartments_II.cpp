#include <bits/stdc++.h>
using namespace std;
void countapartment(int a, int b, int n, int m, vector<char> &c, vector<bool> &v, int &rcnt)
{
    if (a < 0 || a >= n || b < 0 || b >= m || c[a * m + b] == '#' || v[a * m + b])
    {
        return;
    }
    v[a * m + b] = true;
    rcnt++;
    countapartment(a - 1, b, n, m, c, v, rcnt);
    countapartment(a + 1, b, n, m, c, v, rcnt);
    countapartment(a, b - 1, n, m, c, v, rcnt);
    countapartment(a, b + 1, n, m, c, v, rcnt);
}
vector<int> apartment(int n, int m, vector<char> &c)
{
    vector<bool> v(n * m, false);
    vector<int> aptsize;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c[i * m + j] == '.' && !v[i * m + j])
            {
                int rcnt = 0;
                countapartment(i, j, n, m, c, v, rcnt);
                aptsize.push_back(rcnt);
            }
        }
    }
    return aptsize;
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<char> c(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i * m + j];
        }
    }
    vector<int> aptsize = apartment(n, m, c);
    sort(aptsize.begin(), aptsize.end());
    for (int size : aptsize)
    {
        cout << size << " ";
    }

    return 0;
}