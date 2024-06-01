#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// 백준 11051 DP
// 이항 계수 특징과 파스칼 삼각형 이용

constexpr int MOD{ 10007 };

int binomial(int n, int k, vector<vector<int>>& dp)
{
    if (k > n) return 0;
    
    for (int i = 0; i <= n; ++i)
    {
        // nC0 == 1
        dp[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            // nCk = (n - 1)C(k - 1) + (n - 1)Ck
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    return dp[n][k];
}

// 람다 함수 사용
auto binomial = [](int n, int k, auto& dp) -> int
    {
        if (k > n) return 0;

        for (int i = 0; i <= n; ++i)
        {
            dp[i][0] = 1;
            for (int j = 1; j <= i; ++j)
            {
                // nCk = (n - 1)C(k - 1) + (n - 1)Ck
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }

        return dp[n][k];
    };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    cout << binomial(n, k, dp) << "\n";


    return 0;
}
