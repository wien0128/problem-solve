#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 최소회의실개수 19598 PriorityQueue
// O( N logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> meetings(n);
    for (auto& [s, e] : meetings)
    {
        cin >> s >> e;
    }

    // 시작 시간 기준 오름차순
    sort(meetings.begin(), meetings.end());

    // 종료 시간 기준 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(meetings[0].second);    // 첫 번째 회의 종료 시간 삽입

    int minRooms{ 1 };  // 필요한 최소 회의실의 개수
    for (int i = 1; i < n; ++i)
    {
        // 가장 빨리 끝나는 회의가 현재 회의 시작 시간 이전에 끝나면 제거
        if (pq.top() <= meetings[i].first)
        {
            pq.pop();
        }
        // 현재 회의 종료 시간 삽입
        pq.push(meetings[i].second);
        // 필요한 최소 회의실 개수 갱신
        minRooms = max(minRooms, static_cast<int>(pq.size()));
    }

    cout << minRooms;


    return 0;
}
