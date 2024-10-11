#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MAX_N{ 67 };

// Generations_of_Tribbles 9507 DP
// 점화식 그대로 만든 후 출력
// O( 67 + t )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 1로 초기화
    vector<ll> dp(MAX_N + 1, 1);
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= MAX_N; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }


    return 0;
}
