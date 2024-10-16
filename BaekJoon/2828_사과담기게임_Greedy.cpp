#include <iostream>

using namespace std;

// 사과담기게임 2828 Greedy
// 문제 지문이 모호하지만
// 바구니 왼쪽만 신경쓰면 되는 문제
// O( J )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, j;
    // 바구니 왼쪽 끝 포인터, 총 이동 거리
    int left{ 1 }, res{ 0 };
    cin >> n >> m >> j;

    while (j--)
    {
        int apple;
        cin >> apple;

        // 사과가 바구니 왼편에 떨어질 경우
        if (apple < left)
        {
            // 바구니 왼쪽 이동 후 거리 추가
            res += left - apple;
            left = apple;
        }
        // 사과가 바구니 오른편에 떨어질 경우
        else if (apple > left + m - 1)
        {
            // 바구니 오른쪽 이동 후 거리 추가
            res += apple - (left + m - 1);
            // 사과 위치 - 바구니 크기 + 1
            left = apple - m + 1;
        }
    }

    cout << res;
    

    return 0;
}
