#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 12865 DP 0-1 배낭문제

// 배낭에 물건을 넣거나(1), 넣지 않거나(0)
// 의사다항시간안에 풀이 가능, O(nk)
// 짐을 쪼갤 수 있을 경우(무게에 소수 가능) 분할가능 배낭문제


// 배낭에 넣을 수 있는 물건들의 최대가치값
int getKnapsackMaxValue(int n, int k, vector<pair<int, int>>& items)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        int weight = items[i - 1].first;
        int value = items[i - 1].second;

        // j = 배낭 용량
        for (int j = 0; j <= k; j++) 
        {
            // 현재 배낭 용량이 현재 물건보다 작은가?
            if (j < weight) 
            {
                // 담을 수 없다.
                // 이전 단계 최대가치와 같음
                dp[i][j] = dp[i - 1][j];
            }
            else 
            {
                // 담을 수 있다.
                // 1) 이전 단계 최대가치 유지
                // 2) 현재 단계 물건 가치 + 현재 물건 제외 남은 용량 최대가치
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
            }
        }
    }

    return dp[n][k];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    // vector<pair<무게, 가치>>
    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].first >> items[i].second;
    }

    cout << getKnapsackMaxValue(n, k, items) << "\n";


    return 0;
}
