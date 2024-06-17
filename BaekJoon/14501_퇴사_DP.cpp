#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 퇴사 14501 DP
// 역순으로 계산하는 아이디어가 어려웠다.
// 점화식: dp[i] = max(dp[i+1], P[i] + dp[i + T[i])


int getMaximizePay(const vector<pair<int, int>>& tp, int n)
{
    // dp[i] = i일부터 n+1일까지 얻을 수 있는 최대 이익
    vector<int> dp(n + 1, 0);

    for (int day = n - 1; day >= 0; --day)
    {
        // 일하지 않는 경우
        dp[day] = dp[day + 1];

        // 일 할 수 있는 경우
        if (day + tp[day].first <= n)
        {
            //dp[i] = max(dp[i+1], P[i] + dp[i + T[i])              
            dp[day] = max(dp[day], tp[day].second + dp[day + tp[day].first]);
        }
    }

    // 1일 ~ 퇴사일까지의 가능한 최대 이익
    return dp[0];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> tp(n);   // { Ti(기간), Pi(보수) }

    for (int i = 0; i < n; ++i)
    {
        cin >> tp[i].first >> tp[i].second;
    }

    cout << getMaximizePay(tp, n);

    return 0;
}
