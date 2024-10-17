#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MAX_N = 35;

// 점화식 13699 DP
// 카탈란 수열 문제
// O( N^2 )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 0 <= n <= 35
    vector<ll> dp(MAX_N + 1, 0);
    // t(0) = 1
    dp[0] = 1;

    // DP 배열 사전 계산
    // i = 0, 1, 2, 3, ..., n-1
    // j = n-1, n-2, n-3, ..., 0
    for (int i = 1; i <= MAX_N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }

    int n;
    cin >> n;
    
    cout << dp[n];


    return 0;
}
