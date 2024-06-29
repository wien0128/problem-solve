#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 외판원_순회 2098 DP + Bit_Masking
// dp[mask][i] = min(dp[mask][i], dp[mask \ (1 << i)][i] + w[j][i])
// 2 <= n <= 16, Bruteforce로는 1초내에 못 푼다.
// Bruteforce의 경우 O(n!) DP + Bit_Masking의 경우 O(n * 2^n)

// numeric_limits<int>::max(), 오버플로우 남

using Matrix = vector<vector<int>>;
constexpr auto INF = numeric_limits<int>::max() / 2;

// DP + Bit Masking
int tsp(int n, const Matrix& w, Matrix& dp, int mask, int pos)
{
    // 모든 정점 순회한 경우 시작점으로 돌아가는 비용 반환
    if (mask == (1 << n) - 1)
    {
        return w[pos][0] ? w[pos][0] : INF;
    }

    // 이미 계산한 경우 DP 값 반환
    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    // 현재 경로 최소 비용
    int res = INF;

    // 모든 정점 순회
    for (int next = 0; next < n; ++next)
    {
        // 다음 정점을 방문한 적 있거나, 이동 불가능한 경우 무시
        if (mask & (1 << next) || w[pos][next] == 0) continue;
 
        res = min(res, tsp(n, w, dp, mask | (1 << next), next) + w[pos][next]);
    }

    // 현재 위치까지의 최소 비용 저장
    return dp[mask][pos] = res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    Matrix w(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> w[i][j];
        }
    }

    // dp[방문상태][현재도시]
    Matrix dp(1 << n, vector<int>(n, -1));

    cout << tsp(n, w, dp, 1, 0);


    return 0;
}
