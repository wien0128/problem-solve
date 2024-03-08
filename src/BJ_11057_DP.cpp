#include <iostream>
#include <vector>

using namespace std;

// น้มุ 11057 DP

constexpr int MOD = 10007;
constexpr int MAX = 1001;

int dp[MAX][10];

int countAscents(int n)
{
    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    int sum{ 0 };
    for (int i = 0; i < 10; i++)
    {
        sum = (sum + dp[n][i]) % MOD;
    }

    return sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << countAscents(n);

    return 0;
}