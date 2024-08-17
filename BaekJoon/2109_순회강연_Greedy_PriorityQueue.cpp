#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 순회강연 2109 PriorityQueue, Greedy, Align
// 13904번과 매우 유사한 문제
// O( N logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n == 0)  // 예외 처리 중요
    {
        cout << 0;
        return 0;
    }

    vector<pair<int, int>> v(n); // { 강연료, 강연일 }
    for (auto& [p, d] : v)
    {
        cin >> p >> d;
    }

    // 강연일 기준 내림차순, 같은 강연일이면 강연료 기준 내림차순 정렬
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return a.second == b.second ? a.first > b.first : a.second > b.second;
        });

    priority_queue<int> pq; // 강연료 기준 최대 힙
    int totalPay{ 0 };      // 강연료 총계

    // 가능한 마지막 강연일로부터 역순으로 탐색
    // int day: 가장 늦은 강연일
    // int idx: 현재 강연 인덱스
    for (int day = v.front().second, idx = 0; day > 0; --day)
    {
        // 현재 날짜에서 가능한 강연 모두 추가
        while (idx < n && v[idx].second >= day)
        {
            pq.push(v[idx++].first);
        }
        // 현재 날짜에서 가장 높은 강연료의 강의만 선택
        if (!pq.empty())
        {
            totalPay += pq.top();
            pq.pop();
        }
    }

    cout << totalPay;


    return 0;
}
