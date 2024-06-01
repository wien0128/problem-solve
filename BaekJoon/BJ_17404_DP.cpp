#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX{ 100000 };

// 백준 17404 DP
// 빡세다..


int minCost(vector<vector<int>>& cost, int n)
{
    int res{ MAX };

    if (n == 0)
        return 0;

    vector<vector<int>> dp(n + 1, vector<int>(3));

    // 1번 집 색 정하기
    for (int rgb = 0; rgb < 3; rgb++)
    {
        // 1번 집에 지정된 색 이외는 dp에서 제외
        for (int i = 0; i < 3; i++)
        {
            if (i == rgb)
            {
                dp[0][i] = cost[0][i];
            }
            else
            {
                dp[0][i] = MAX;
            }
        }

        // DP
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
        }

        // 1번 집과 N번 집 색 중복 방지
        for (int i = 0; i < 3; i++)
        {
            if (i == rgb)
            {
                continue;
            }
            else
            {
                res = min(res, dp[n - 1][i]);
            }
        }
    }

    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<vector<int>> cost(n + 1, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    cout << minCost(cost, n);


    return 0;
}
