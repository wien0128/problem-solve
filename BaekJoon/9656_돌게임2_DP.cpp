#include <iostream>

using namespace std;

// 돌게임2 9656 DP
// dp[n] = !dp[n - 1] || !dp[n - 3]
// O( 1 )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    /*
    
    bool dp[n + 1];

    dp[0] = false; dp[1] = ture;
    dp[2] = true; dp[3] = true;

    for (int i = 4; i <= n; ++i)
    {
        dp[i] = !dp[i - 1] || !dp[i - 3];
    }

    if (dp[n]) cout << "SK";
    else cout << "CY";

    */

    if (n % 2 == 1) cout << "CY";
    else cout << "SK";


    return 0;
}
