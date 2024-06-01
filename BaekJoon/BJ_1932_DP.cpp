#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// BJ 1932 DP
// Bottom-Up


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> dp[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            //          max(왼쪽 대각선 아래, 오른쪽 대각선 아래) 
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    
    cout << dp[0][0];


    return 0;
}