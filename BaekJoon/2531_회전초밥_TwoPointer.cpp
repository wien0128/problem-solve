#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 회전초밥 2531 TwoPointer
// 먹을 수 있는 초밥 가짓수의 최댓값 구하기
// O(2N + k) -> O(N)


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> sushi(n);   // 초밥 종류
    for (int& s : sushi)
    {
        cin >> s;
    }

    vector<int> sushiCnt(d + 1, 0); // 초밥 종류별 개수
    int uniqueSushi{ 0 };   // 현재 윈도우 내 고유한 초밥 종류 수

    // 초기 윈도우 내 고유한 초밥 개수 세기
    for (int i = 0; i < k; ++i)
    {
        if (sushiCnt[sushi[i]]++ == 0)
        {
            ++uniqueSushi;
        }
    }

    int maxUniqueSushi{ uniqueSushi };  // 최대 고유 초밥 종류 수
    if (sushiCnt[c] == 0)   // 쿠폰 여부
    {
        ++maxUniqueSushi;   // 초밥 종류 증가
    }

    // 슬라이딩 윈도우
    for (int i = 1; i < n; ++i)
    {
        // 윈도우에서 제거하는 초밥의 개수가 0이면
        // 고유 초밥 개수 감소
        if (--sushiCnt[sushi[i - 1]] == 0)
        {
            --uniqueSushi;
        }

        // 새로운 초밥 추가
        if (sushiCnt[sushi[(i + k - 1) % n]]++ == 0)
        {
            ++uniqueSushi;
        }

        int curUniqueSushi{ uniqueSushi };  // 현재 윈도우 내 고유 초밥 종류 수
        if (sushiCnt[c] == 0)   // 쿠폰 여부
        {
            ++curUniqueSushi;   // 초밥 종류 증가
        }

        maxUniqueSushi = max(maxUniqueSushi, curUniqueSushi);
    }

    cout << maxUniqueSushi;


    return 0;
}
