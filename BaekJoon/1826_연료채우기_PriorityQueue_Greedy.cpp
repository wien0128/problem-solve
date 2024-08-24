#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 연료채우기 1826 PriorityQueue, Greedy
// O( NlogN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 주유소 위치와 연료량 벡터
    // { 위치, 연료량 }
    vector<pair<int, int>> stations(n);
    for (auto& [p, f] : stations)
    {
        cin >> p >> f;
    }

    int L;  // 마을까지 필요한 연료량
    int P;  // 현재 연료량
    cin >> L >> P;

    // 주유소 위치 기준 오름차순 정렬
    sort(stations.begin(), stations.end());

    // 최대 힙
    priority_queue<int> maxHeap;

    int cnt{ 0 };   // 연료 채운 횟수
    int idx{ 0 };

    while (P < L)
    {
        // 현재 연료로 도달 가능한 모든 주유소 push
        while (idx < n && stations[idx].first <= P)
        {
            maxHeap.push(stations[idx++].second);
        }

        // 현재 연료로 갈 수 있는 
        // 주유소가 없으면 마을 도착 불가능
        if (maxHeap.empty())
        {
            cout << -1 << "\n";
            return 0;
        }

        // 가장 많은 연료를 가진 주유소 방문
        P += maxHeap.top();
        maxHeap.pop();
        ++cnt;
    }

    cout << cnt;


    return 0;
}
