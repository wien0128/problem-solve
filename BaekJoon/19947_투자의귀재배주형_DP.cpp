#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 투자의귀재배주형 19947 DP
// dp[i] = max(dp[i], (dp[i - 1] * 1.05), 
//            (dp[i - 3] * 1.20), dp[i - 5] * 1.35))
// O( Y )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, y;
    cin >> h >> y;

    vector<int> dp(y + 1, h);

    // dp[i] = i년 후에 얻을 수 있는 최대 기대수익
    for (int i = 1; i <= y; ++i)
    {
        // 1년 후 기대수익
        dp[i] = max(dp[i], static_cast<int>(dp[i - 1] * 1.05));
        // 3년 후 기대수익
        if (i >= 3) 
            dp[i] = max(dp[i], static_cast<int>(dp[i - 3] * 1.2));
        // 5년 후 기대수익
        if (i >= 5) 
            dp[i] = max(dp[i], static_cast<int>(dp[i - 5] * 1.35));
    }

    cout << dp[y];


    return 0;
}
