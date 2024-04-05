#include <iostream>
#include <vector>

using namespace std;

// 백준 1904 DP
// 또보나치

constexpr int MOD{ 15746 };

int tileCases(int n)
{
    vector<int> dp(n + 2);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    dp[5] = 8;

    for (int i = 6; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    return dp[n];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    cout << tileCases(n);


    return 0;
}
