#include <iostream>
#include <vector>

using namespace std;

// BJ 2133 DP
// dp[i] = dp[i - 2] * 3 + (2 * sum(dp[0]...dp[i - 4]))
// 골드는 어렵네...


int fillTiles(int n) {
    if (n % 2 == 1) // 홀수는 못 채움
        return 0;

    vector<int> dp(n + 1);

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i += 2) 
    {
        // 2*1 타일 채우기
        dp[i] = dp[i - 2] * 3; 

        for (int j = 0; j <= i - 4; j += 2) 
        {
            // 1*2 타일 채우기
            dp[i] += dp[j] * 2; 
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

    if (n % 2 == 1)
    {
        cout << 0;
        return 0;
    }

    cout << fillTiles(n);


    return 0;
}
