#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

// 최소회의실개수 19598 Sweeping
// O( N logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pii> meetings;
    meetings.reserve(2 * n);

    for (int i = 0; i < n; ++i)
    {
        int s, e;
        cin >> s >> e;
        meetings.emplace_back(s, 1);    // 시작 시간 +1
        meetings.emplace_back(e, -1);   // 종료 시간 -1
    }

    // 시간순 오름차순 정렬
    sort(meetings.begin(), meetings.end(), [](const pii& a, const pii& b) {
        // 같은 시작 시간일 경우
        if (a.first == b.first)
        {
            // 종료 시간 기준 정렬
            return a.second < b.second;
        }
        // 시작 시간 기준 정렬
        return a.first < b.first;
        });
    
    int minRooms{ 0 }; // 필요한 최소 회의실 개수
    int curRooms{ 0 }; // 현재 사용 중인 회의실 개수

    // 모든 회의 순회하며 회의실 개수 계산
    for (const auto& m : meetings)
    {
        curRooms += m.second; // +1 or -1
        minRooms = max(minRooms, curRooms);
    }

    cout << minRooms;


    return 0;
}
