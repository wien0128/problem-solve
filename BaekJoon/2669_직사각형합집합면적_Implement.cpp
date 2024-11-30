#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

// 직사각형합집합 2669 Implement
// O( n * w * h * 100^2 )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 100 * 100 평면 boolean 공간 2차원 배열
    array<array<bool, 100>, 100> grid = {};


    for (int i = 0; i < 4; ++i)
    {
        // 사각형 좌하단, 우상단 좌표 입력
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 격자 영역 순회하며 true 설정
        for (int x = x1; x < x2; ++x)
        {
            for (int y = y1; y < y2; ++y)
            {
                grid[x][y] = true;
            }
        }
    }

    int area{ 0 };  // 면적
    for (const auto& row : grid)
    {
        // 각 행에서 true로 설정된 셀의 개수를 카운트
        area += count(row.begin(), row.end(), true);
    }

    cout << area;

    
    return 0;
}
