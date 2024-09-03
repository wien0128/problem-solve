#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 도영이가만든맛있는음식 2961 BackTracking
// O( 2^n )


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

    // 백트래킹
    auto DFS = [&](auto&& self, int idx, int S, int B) -> void {
        // n 개의 재료를 모두 선택했다면
        if (idx == n)
        {
            // 적어도 하나 이상 재료를 선택했다면
            if (S != 1 || B != 0)
            {
                // 최소 차이 갱신
                minDiff = min(minDiff, abs(S - B));
            }
            return;
        }

        // 현재 재료를 선택하는 경우
        self(self, idx + 1, S * v[idx].first, B + v[idx].second);
        // 현재 재료를 선택하지 않는 경우
        self(self, idx + 1, S, B);
        };

    DFS(DFS, 0, 1, 0);

    cout << minDiff;
    

    return 0;
}
