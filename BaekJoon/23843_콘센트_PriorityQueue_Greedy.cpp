#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 콘센트 23843 PriorityQueue + Greedy
// O( N logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> times(n);   // 기기별 충전 시간
    for (int& t : times)
    {
        cin >> t;
    }

    // 긴 순서대로 내림차순 정렬
    sort(times.rbegin(), times.rend());

    // 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < m; ++i) // pq 초기화
    {
        pq.push(0);
    }

    int minTime{ 0 };   // 모든 기기가 충전되는데 걸리는 최소 시간
    for (int i = 0; i < n; ++i)
    {
        // 충전이 가장 빨리 끝나는 콘센트에
        // 가장 오래 걸리는 기기 충전
        int cur = pq.top() + times[i];
        pq.pop();
        pq.push(cur);
        
        minTime = max(minTime, cur);
    }

    cout << minTime;


    return 0;
}
