#include <bits/stdc++.h>
using namespace std;
map<int, bool> m;
bool makeit(int n)
{
    if (n == 1)
    {
        return true;
    }
    if (n < 1)
    {
        return false;
    }
    if (m.find(n) != m.end())
    {
        return m[n];
    }
    return m[n] = makeit(n - 3) || (n % 2 == 0 && makeit(n / 2));
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p;
        cin >> p;
        if (makeit(p))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        m.clear();
    }

    return 0;
}