#include <iostream>
#include <vector>

// 백준 1309 DP
// dp[n] = dp[n - 1] * 2 + dp[n - 2]

using namespace std;

constexpr int MOD = 9901;


int cntLionLocate(int n)
{
    vector<int> dp(n + 1);

    dp[0] = 1;
    dp[1] = 3;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % MOD;
    }

    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    cout << cntLionLocate(n) << '\n';


    return 0;
}
