#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 스카이라인 1933 Sweeping, Set
// 끝점 처리가 굉장히 까다롭다
// 코너케이스에 유의
// O( N logN )


class Building {
public:
    int x, h;       // x 좌표, 높이
    bool isStart;   // true 면 시작점, false 면 끝점

    Building(int x, int h, bool s) : x(x), h(h), isStart(s) {}
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<Building> buildings; // 건물 벡터
    buildings.reserve(2 * n);   // 메모리 최적화

    for (int i = 0; i < n; ++i)
    {
        int L, H, R;
        cin >> L >> H >> R;
        buildings.emplace_back(L, H, true);     // 시작점
        buildings.emplace_back(R, H, false);    // 끝점
    }

    // x 좌표 기준 오름차순
    // x 좌표가 같다면, 시작점 우선
    // 시점끼리는 높이 기준 내림차순, 끝점끼리는 오름차순 정렬
    sort(buildings.begin(), buildings.end(), [](const Building& a, const Building& b) {
        if (a.x != b.x) return a.x < b.x;
        if (a.isStart != b.isStart) return a.isStart > b.isStart;
        return a.isStart ? a.h > b.h : a.h < b.h;
    });

    multiset<int> heights;          // 현재 건물 높이 관리 셋
    heights.insert(0);              // 바닥 표현 설정
    vector<pair<int, int>> skyline; // { x 좌표, 높이 }, 변환점 벡터
    int prevHeight{ 0 };            // 이전 변환점 높이

    // 스위핑
    for (const auto& b : buildings)
    {
        // 시작점은 높이 추가
        if (b.isStart)
        {
            heights.insert(b.h);
        }
        // 끝점은 해당 높이 제거
        else
        {
            heights.erase(heights.find(b.h));
        }

        // 현재 최대 높이
        int curHeight = *heights.rbegin();

        // 높이가 달라졌다면 스카이라인에 추가
        // 모든 높이를 저장할 필요 없음
        // 변환점만 표현하면 충분
        if (curHeight != prevHeight)
        {
            skyline.emplace_back(b.x, curHeight);
            prevHeight = curHeight;
        }
    }

    for (const auto& [x, h] : skyline)
    {
        cout << x << " " << h << " ";
    }
    cout << "\n";


    return 0;
}
