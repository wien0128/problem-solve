#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 게임을만든동준이 2847 Greedy
// O( N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> levels(n);
    for (int& l : levels)
    {
        cin >> l;
    }

    int res{ 0 };   // 총 조정 횟수
    for (int i = n - 2; i >= 0; --i)
    {
        // 현재 레벨 점수 다음 레벨 점수보다 크면 조정
        if (levels[i] >= levels[i + 1])
        {
            // 조정값 계산
            res += levels[i] - levels[i + 1] + 1;
            // 현재 레벨 점수를 다음 레벨보다 - 1
            levels[i] = levels[i + 1] - 1;
        }
    }

    cout << res;

    return 0;
}
