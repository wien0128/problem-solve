#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 철로 13334 PriorityQueue, Sweeping
// 전형적인 라인 스위핑 문제
// O( NlogN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // { 시점, 종점 }
    vector<pair<int, int>> lines(n);
    for (int i = 0; i < n; ++i)
    {
        int s, e;
        cin >> s >> e;
        if (s > e) swap(s, e); // 시점이 종점보다 항상 작게
        lines[i] = { s, e };
    }

    int d;
    cin >> d;

    // 종점 기준 오름차순 정렬
    // 종점이 같다면 시점 기준 오름차순 정렬
    sort(lines.begin(), lines.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    // 최소 힙, 현재 철로에 포함된 시점 관리
    priority_queue<int, vector<int>, greater<>> pq;
    int maxCnt{ 0 };    // 철로에 포함된 라인의 개수

    // 스위핑
    for (const auto& [s, e] : lines)
    {
        pq.push(s); // 현재 구간 시점을 push

        // 철로 길이에 포함되지 않는 시점 제거
        while (!pq.empty() && pq.top() < e - d)
        {
            pq.pop();
        }
        maxCnt = max(maxCnt, static_cast<int>(pq.size()));
    }

    cout << maxCnt;


    return 0;
}
