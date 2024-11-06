#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 병든나이트 1783 Greedy
// 그림을 그려 패턴을 찾자
// O( 1 )

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;   // 세로, 가로
    cin >> n >> m;

    if (n == 1)
    {
        // 세로 크기가 1이면 이동 불가
        cout << 1;
    }
    else if (n == 2)
    {
        // 2칸 위로/아래로 + 1칸 오른쪽만 가능
        // 단, 최대 4번까지 = 4칸이 상한
        // m < 7인 경우 더 적게 이동
        cout << min(4, (m + 1) / 2);
    }
    else
    {
        // 네 가지 이동 방식 모두 가능
        // m < 7인 경우 최대값은 4, 그외는 m칸이 최대
        // m >= 7인 경우 4칸은 고정적으로 이동, 이후 모든 칸 방문 가능
        // 따라서, m - 2
        cout << (m < 7 ? min(4, m) : m - 2);
    }


    return 0;
}
