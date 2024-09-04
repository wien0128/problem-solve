#include <iostream>
#include <vector>

using namespace std;

constexpr int MIN_POWER{ 500 };

// 근손실 18429 BackTracking
// O( N! )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, res{ 0 };
    cin >> n >> k;

    vector<int> kits(n);
    for (int& kit : kits)
    {
        cin >> kit;
    }

    auto DFS = [&](auto&& self, int day, int power, vector<bool>& isUsed) -> void {
        // 모든 운동 키트를 사용했다면
        if (day == n)
        {
            ++res;
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            // 이미 사용한 키트 건너뜀
            if (isUsed[i]) continue;

            isUsed[i] = true;
            // 새로운 무게가 최소 파워 이상이면 다음 날로
            if (power - k + kits[i] >= MIN_POWER)
            {
                self(self, day + 1, power - k + kits[i], isUsed);
            }
            isUsed[i] = false;  // 백트래킹
        }
        };

    // 키트 사용 여부 벡터
    vector<bool> isUsed(n, false);

    DFS(DFS, 0, MIN_POWER, isUsed);

    cout << res;
    

    return 0;
}
