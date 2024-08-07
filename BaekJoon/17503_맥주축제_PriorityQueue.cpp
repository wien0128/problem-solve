#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// 맥주축제 17503 PriorityQueue
// 지문 잘 읽자...
// O( K logK + K logN )


struct Bear {
    int preference;    // 선호도
    int proof;      // 도수
};

// 도수 기준 오름차순 비교자
bool cmp(const Bear& a, const Bear& b)
{
    return a.proof < b.proof;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<Bear> bears(k);  // 맥주 종류
    for (int i = 0; i < k; ++i)
    {
        cin >> bears[i].preference >> bears[i].proof;
    }

    // 도수 기준 맥주 오름차순
    sort(bears.begin(), bears.end(), cmp);

    // 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;
    // 선호도의 총 합
    ll totalUtility{ 0 };

    for (const auto& bear : bears)
    {
        pq.push(bear.preference);         // 현재 맥주 삽입
        totalUtility += bear.preference;

        // n + 1 개의 맥주를 선택했다면
        if (pq.size() > n)
        {
            // 가장 작은 선호도의 맥주를 뺌
            totalUtility -= pq.top();
            pq.pop();
        }

        // n 개의 맥주를 마시고, 먹은 맥주들의 선호도 총 합이 m 이상이라면
        if (pq.size() == n && totalUtility >= m)
        {
            // 마지막에 먹은 맥주의 도수가 정답
            cout << bear.proof;
            return 0;
        }
    }

    cout << -1;


    return 0;
}
