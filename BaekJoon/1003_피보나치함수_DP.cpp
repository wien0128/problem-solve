#include <iostream>
#include <array>

using namespace std;

// 피보나치함수 1003 DP
// 그냥 피보나치
// O( T )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    // 0과 1 호출 횟수 저장 배열
    array<pair<int, int>, 41> dp = {};
    dp[0] = { 1, 0 };   // fibonacci(0) 호출 횟수
    dp[1] = { 0, 1 };   // fibonacci(1) 호출 횟수

    for (int i = 2; i <= 40; ++i)
    {
        dp[i] = { dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second };
    }

    while (T--)
    {
        int x;
        cin >> x;
        cout << dp[x].first << " " << dp[x].second << "\n";
    }

    
    return 0;
}
