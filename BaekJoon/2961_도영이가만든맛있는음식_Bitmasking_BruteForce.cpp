#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 도영이가만든맛있는음식 2961 Bitmasking, BruteForce
// O( n * 2^n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);    // { 신맛, 쓴맛 }
    for (auto& [s, b] : v)
    {
        cin >> s >> b;
    }

    // 신맛과 쓴맛의 최소차이
    int minDiff = numeric_limits<int>::max();

    // 비트마스킹 + 브루트포스
    // 모든 재료의 부분 집합 탐색
    // 공집합은 제외 ( i = 1 )
    for (int i = 1; i < (1 << n); ++i)
    {
        int s = 1, b = 0;
        for (int j = 0; j < n; ++j)
        {
            // j 번째 재료가 포함된다면
            if (i & (1 << j))
            {
                s *= v[j].first;    // 신맛은 곱
                b += v[j].second;   // 쓴맛은 합
            }
        }

        minDiff = min(minDiff, abs(s - b));
    }

    cout << minDiff;
    

    return 0;
}
