#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

// 정사각형 1485 Sorting, Math
// 정사각형의 조건
// = 네 변의 길이가 같을 것
// = 대각선의 길이가 같을 것
// -> 고대로 구현
// O( n log n )


// 좌표 구조체
struct Point {
    int x, y;
};

// 두 점 간의 거리를 제곱하는 함수
int distSquared(const Point& a, const Point& b)
{
    // 거리의 제곱으로만 계산
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

// 네 점이 정사각형인지 확인하는 함수
bool isSquare(const array<Point, 4>& points)
{
    // 6개의 점 간의 거리를 제곱으로 저장
    array<int, 6> dist;
    int idx{ 0 };

    for (int i = 0; i < 4; ++i)
    {
        for (int j = i + 1; j < 4; ++j)
        {
            // 점 i와 점 j간의 거리를 제곱으로 계산
            dist[idx++] = distSquared(points[i], points[j]);
        }
    }

    // 오름차순
    // [0~3]은 네 변의 길이, [4~5]는 대각선의 길이
    sort(dist.begin(), dist.end());

    // 정사가형이라면 1, 아니라면 0
    return dist[0] > 0 &&       // 네 점의 위치가 모두 다른가?
        dist[0] == dist[1] &&
        dist[1] == dist[2] &&
        dist[2] == dist[3] &&   // 네 변의 길이가 같은가?
        dist[4] == dist[5] &&   // 대각선의 길이가 같은가?
        dist[0] * 2 == dist[4]; // 대각선의 길이가 변의 길이의 2배인가?
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        array<Point, 4> points;
        for (auto& p : points)
        {
            cin >> p.x >> p.y;
        }

        cout << (isSquare(points) ? 1 : 0) << "\n";
    }


    return 0;
}
