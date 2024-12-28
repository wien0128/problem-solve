#include <iostream>
#include <vector>

using namespace std;

// 색종이2 2567 Implementation
// 둘레 구하기 문제
// O( 100^2 )

constexpr int SIZE{ 101 };          // 도화지 사이즈
constexpr int dx[4]{ -1, 1, 0, 0 }; // 상하
constexpr int dy[4]{ 0, 0, -1, 1 }; // 좌우

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 100 * 100 도화지 2차원 벡터
    // 1 이면 색종이가 덮인 부분
    vector<vector<int>> canvas(SIZE, vector<int>(SIZE, 0));

    while (n--)
    {
        int x, y;
        cin >> x >> y;

        // (x, y) 를 시작점으로 10 * 10 크기 영역 표시
        for (int i = x; i < x + 10; ++i)
        {
            for (int j = y; j < y + 10; ++j)
            {
                canvas[i][j] = 1;
            }
        }
    }

    int perimeter{ 0 };  // 둘레

    // 색종이가 덮은 영역 계산 O(100 * 100)
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            // 색종이가 덮인 칸이라면 상하좌우 탐색
            if (canvas[i][j])
            {
                for (int d = 0; d < 4; ++d)
                {
                    // 현재 칸 대비 인접 칸이 빈 칸일 
                    // 경우 현재 영역의 경계(둘레)
                    // = 둘레 증가
                    if (!canvas[i + dx[d]][j + dy[d]])
                    {
                        ++perimeter;
                    }
                }
            }
        }
    }

    cout << perimeter;


    return 0;
}
