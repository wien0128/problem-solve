#include <iostream>
#include <vector>

using namespace std;

// BJ 13398 DP
// dp[i][0] = i번째까지의 최대 연속합 but 삭제를 X
// dp[i][0] = i번째까지의 최대 연속합 but 삭제를 O


int largestSum(int n, const vector<int>& v)
{
    vector<vector<int>> dp(n, vector<int> (2, 0));

    dp[0][0] = dp[0][1] = v[0];
    int maxSum = v[0];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + v[i], v[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + v[i]);
        maxSum = max({maxSum, dp[i][0], dp[i][1]});
    }

    return maxSum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << largestSum(n, v);


    return 0;
}
