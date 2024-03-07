#include <iostream>
#include <vector>

using namespace std;

// น้มุ 2225 DP
// DP[k][n] = DP[k][n - 1] + DP[k - 1][n]

constexpr int MOD = 1000000000;
using ll = long long;

ll dp[201][201];

ll disassemble(int n, int k)
{
    for (int i = 0; i <= k; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    return dp[k][n];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;

    cout << disassemble(n, k);


    return 0;
}