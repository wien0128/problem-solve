#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 거스름돈 14916 DP
// dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if (n == 1 || n == 3)
    {
        cout << -1;
        return 0;
    }

    // dp[i] = i 를 만들기 위한 최소 동전 개수
    // dp[i] = -1, 만들 수 없거나, 계산 전
    vector<int> dp(n + 1, -1);

    if (n >= 2) dp[2] = 1; dp[4] = 2;
    if (n >= 5) dp[5] = 1;

    for (int i = 6; i <= n; ++i)
    {
        // i - 2가 가능한 경우
        if (dp[i - 2] != -1) dp[i] = dp[i - 2] + 1;
        // i - 2와 i - 5의 경우 중 최소값 선택
        if (dp[i - 5] != -1) dp[i] = min(dp[i], dp[i - 5] + 1);
    }

    cout << dp[n];

    
    return 0;
}
