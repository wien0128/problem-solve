#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// FourSquares 17626 DP, BruteForce
// dp[i] = min(dp[i], dp[i - j^2] + 1)
// O( N루트N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n + 1, numeric_limits<int>::max());
    dp[0] = 0;

    // dp[i] = 수 i를 제곱수의 최소 개수로 
    // 표현하는데 필요한 최소 개수
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1, sq = 1; sq <= i; ++j, sq = j * j)
        {
            dp[i] = min(dp[i], dp[i - sq] + 1);
        }
    }

    cout << dp[n];

    
    return 0;
}
