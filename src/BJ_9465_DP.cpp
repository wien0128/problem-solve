#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// น้มุ 9465 DP
// dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + row1[i])
// dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + row2[i])

int calculateStickerScore(int n, const vector<int>& row1, const vector<int>& row2)
{
    vector<vector<int>> dp(2, vector<int>(n, 0));

    dp[0][0] = row1[0];
    dp[1][0] = row2[0];

    for (int i = 1; i < n; i++)
    {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + row1[i]);
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + row2[i]);
    }

    return max(dp[0][n - 1], dp[1][n - 1]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> row1(n);
        for (int i = 0; i < n; i++)
        {
            cin >> row1[i];
        }

        vector<int> row2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> row2[i];
        }

        cout << calculateStickerScore(n, row1, row2) << '\n';
    }


    return 0;
}