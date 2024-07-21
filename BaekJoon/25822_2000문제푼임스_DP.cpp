#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2000문제푼임스 25822 DP
// O( N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double c;
    int n;
    cin >> c >> n;

    vector<int> solved(n);
    for (int& s : solved)
    {
        cin >> s;
    }

    // 최대 스트릭 프리즈 개수 계산
    int maxFreezes{ min(2, static_cast<int>(c / 0.99)) }; // 최대 사용 가능한 프리즈 개수
    int maxSolved{ *max_element(solved.begin(), solved.end()) }; // 가장 많이 푼 문제 수
    int maxStreak{ 0 }; // 최대 스트릭 유지 일수

    // dp[i][j] = i번째 날까지 j개의 프리즈를 사용했을 때의 최대 스트릭 일수
    vector<vector<int>> dp(n + 1, vector<int>(maxFreezes + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= maxFreezes; ++j)
        {
            // 문제를 푼 날이라면
            if (solved[i - 1] > 0)
            {
                dp[i][j] = dp[i - 1][j] + 1;
            }
            // 문제를 풀지 못했고, 프리즈를 사용할 수 있다면
            else if (j > 0)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // 문제를 풀지 못했고, 프리즈를 사용할 수 없다면
            else
            {
                dp[i][j] = 0;
            }

            maxStreak = max(maxStreak, dp[i][j]);
        }
    }

    cout << maxStreak << "\n" << maxSolved;


    return 0;
}
