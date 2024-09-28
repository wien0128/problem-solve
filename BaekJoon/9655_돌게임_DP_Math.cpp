#include <iostream>

using namespace std;

// 돌게임 9655 DP, Math
// dp[n] = !dp[n - 1] or !dp[n - 3]
// O( 1 )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if (n % 2 == 1) cout << "SK";
    else cout << "CY";

    
    return 0;
}
