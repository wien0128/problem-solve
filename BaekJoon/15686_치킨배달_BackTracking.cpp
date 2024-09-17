#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

// 치킨배달 15686 BackTracking
// 도시에서 M개의 치킨집을 선택해 최소 치킨 거리를 찾는 문제
// O( cCm * H * M )


// 좌표 {x, y} 구조체
struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int N, M;
// 집/치킨집들의 좌표 벡터
vector<Point> houses, chickens;
// 치킨집 선택 여부 벡터
vector<bool> isSelected;
// 최소 도시-치킨 거리
int minDistance{ numeric_limits<int>::max() };


// 두 Point 사이 거리 반환
inline int getDistance(const Point& a, const Point& b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// 현재 선택한 치킨집들의 도시-치킨 거리 반환
int getCityToChickenDistance()
{
    int totalDistance{ 0 }; // 도시 전체 치킨 거리

    // 모든 집에 대해 가장 가까운 치킨집까지 거리 계산
    for (const auto& h : houses)
    {
        // 각 집에서 가장 가까운 치킨집까지의 거리
        int dist{ numeric_limits<int>::max() };

        // 선택된 치킨집에 대해서만 거리 계산
        for (int i = 0; i < chickens.size(); ++i)
        {
            if (isSelected[i])
            {
                dist = min(dist, getDistance(h, chickens[i]));
            }
        }

        totalDistance += dist;
    }

    return totalDistance;
}

// @param idx 현재 탐색하는 치킨집 인덱스
// @param depth 선택한 치킨집 수
void selectChicken(int idx, int depth)
{
    // M개의 치킨집을 모두 선택했다면 
    // 도시-치킨 거리 계산
    if (depth == M)
    {
        minDistance = min(minDistance, getCityToChickenDistance());
        return;
    }

    // 모든 치킨집을 순회했다면 리턴
    if (idx == chickens.size()) return;

    // 현재 치킨집을 선택하는 경우
    isSelected[idx] = true;
    selectChicken(idx + 1, depth + 1);

    // 현재 치킨집을 선택하지 않은 경우
    isSelected[idx] = false;
    selectChicken(idx + 1, depth);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;

    // 집/치킨집 위치 입력 {x, y}
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int val;
            cin >> val;

            if (val == 1) houses.emplace_back(i, j);
            else if (val == 2) chickens.emplace_back(i, j);
        }
    }

    isSelected.resize(chickens.size(), false);

    selectChicken(0, 0);

    cout << minDistance;

    
    return 0;
}
