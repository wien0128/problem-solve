#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 파스칼의삼각형 16395 DP
// dp[n][k] = dp[n-1][k-1] + dp[n-1][k]
// O( n * k )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // 파스칼 삼각형의 양 끝은 1로 고정
    vector<int> dp(k, 1);

    // n행 까지 반복
    for (int i = 1; i < n - 1; ++i)
    {
        // k열 이후의 값은 필요 없기에 범위 제한
        // 역순으로 갱신해야 덮어쓰기 방지 가능
        for (int j = min(i, k - 1); j > 0; --j)
        {
            // 왼쪽 위의 값을 더해서 갱신
            dp[j] += dp[j - 1];
        }
    }

    // n행 k열 값 출력
    cout << dp[k - 1];


    return 0;
}
