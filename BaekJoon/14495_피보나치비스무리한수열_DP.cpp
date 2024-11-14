#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// 피보나치비스무리한수열 14495 DP
// 그냥 피보나치
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if (n <= 3)
    {
        cout << 1;
        return 0;
    }

    ll dp[4] = { 1, 1, 1, 0 };
    for (int i = 4; i <= n; ++i)
    {
        // DP[i] = DP[i - 1] + DP[i - 3]
        // 한 칸씩 밀어내며 DP, 메모리 최적화
        dp[3] = dp[2] + dp[0];
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[3];
    }

    cout << dp[3];


    return 0;
}
