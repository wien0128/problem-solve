#include <iostream>
#include <vector>

using namespace std;

// 백준 1149 DP
// n번 째 집을 색칠할 경우, n-1번 째 집과 다른 색 중 적은 비용이
// 드는 색을 선택.


int minCost(vector<vector<int>>& cost)
{
    int n = cost.size();

    if (n == 0)
        return 0;
    
    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0] = cost[0];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<vector<int>> cost(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cost[i][j];
        }
    }

    cout << minCost(cost);


    return 0;
}
