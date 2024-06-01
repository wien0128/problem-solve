#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 백준 1699 DP

int squareSum(int n)
{
    vector<int> dp(n + 1, 2147483647);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
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

    cout << squareSum(n);


    return 0;
}
