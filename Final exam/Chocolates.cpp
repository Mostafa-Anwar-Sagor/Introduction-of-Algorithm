#include <bits/stdc++.h>
using namespace std;
bool chocolate(int n, vector<int> &c)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += c[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }

    int p = sum / 2;

    vector<vector<bool>> dp(n + 1, vector<bool>(p + 1, false));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= c[i - 1])
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - c[i - 1]];
            }
        }
    }
    return dp[n][p];
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        if (chocolate(n, c))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}