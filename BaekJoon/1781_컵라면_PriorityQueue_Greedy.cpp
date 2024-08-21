#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 컵라면 1781 PriorityQueue
// O( NlogN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // { 데드라인, 컵라면 }
    vector<pair<int, int>> problems(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> problems[i].first >> problems[i].second;
    }

    // 데드라인 기준 오름차순 정렬
    sort(problems.begin(), problems.end());

    priority_queue<int, vector<int>, greater<>> pq; // 최소 힙
    long long res{ 0 };

    // 그리디
    for (const auto& p : problems)
    {
        // 현재 문제를 해결할 수 있다면
        // pq.size() == 현재 데드라인
        if (pq.size() < p.first)
        {
            pq.emplace(p.second);
            res += p.second;
        }
        // 현재 문제의 보상이 기존 최소 보상보다 크다면
        // 보상이 큰 문제로 대체
        else if (pq.top() < p.second)
        {
            res -= pq.top();
            pq.pop();
            pq.emplace(p.second);
            res += p.second;
        }
    }

    cout << res;


    return 0;
}
