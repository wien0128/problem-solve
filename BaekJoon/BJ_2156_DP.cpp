#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// BJ 2156 DP
// dp[i] = max({ dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i] })


int maxWine(int n, const vector<int>& wines)
{
    vector<int> dp(n + 1, 0);

    dp[1] = wines[1];
    dp[2] = wines[1] + wines[2];

    for (int i = 3; i <= n; i++)
    {
        dp[i] = max({ dp[i - 1], dp[i - 2] + wines[i], dp[i - 3] + wines[i - 1] + wines[i] });
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

    vector<int> wines(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> wines[i];
    }

    cout << maxWine(n, wines);


    return 0;
}