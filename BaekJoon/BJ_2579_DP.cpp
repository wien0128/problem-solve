#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2579 DP
// DP[n] = max(DP[n - 2], DP[n - 3] + arr[n - 1]) + arr[n]


int calMaxScore(const vector<int>& stairScore, int n) 
{
    // 계단이 하나뿐 일 경우 처리
    if (n <= 1)
        return stairScore[n];

    vector<int> maxScore(n + 1);

    // 1~2번째 계단 점수 저장
    maxScore[1] = stairScore[1];
    maxScore[2] = stairScore[1] + stairScore[2];

    // 현재 계단을 밟는 경우와 밟지 않는 경우 중 max 선택
    for (int i = 3; i <= n; i++) {
        maxScore[i] = max(maxScore[i - 2], maxScore[i - 3] + stairScore[i - 1]) + stairScore[i];
    }

    return maxScore[n];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> stairScore(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> stairScore[i];
    }

    cout << calMaxScore(stairScore, n) << '\n';


    return 0;
}
