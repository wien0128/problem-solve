#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// 타일장식물 13301 DP
// 간단한 피보나치 문제
// O( n )


ll fibo(int n)
{
    vector<ll> dp(81);

    dp[1] = 4;
    dp[2] = 6;
    dp[3] = 10;
    dp[4] = 16;
    dp[5] = 26;

    for (int i = 6; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    cout << fibo(n);

    return 0;
}
