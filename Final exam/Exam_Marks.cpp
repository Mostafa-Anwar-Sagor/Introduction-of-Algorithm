#include <bits/stdc++.h>
using namespace std;

bool can_meet_score(int target_score, const vector<int> &marks)
{

    vector<bool> dp(target_score + 1, false);

    dp[0] = true;

    for (int mark : marks)
    {

        for (int j = target_score; j >= mark; j--)
        {

            if (dp[j - mark])
            {
                dp[j] = true;
            }
        }
    }

    return dp[target_score];
}

int main()
{
    int T;
    cin >> T;

    bool printYES = false;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        vector<int> marks(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> marks[i];
        }

        bool can_achieve = can_meet_score(M, marks);

        if (can_achieve == printYES)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        printYES = !printYES;
    }

    return 0;
}