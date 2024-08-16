#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 과제 13904 PriorityQueue, Greedy, Align
// O( N logN )


struct Assignment {
    int deadline;   // 마감일까지 남은 일수
    int score;      // 점수
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<Assignment> v(n);    // 과제 벡터
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].deadline >> v[i].score;
    }

    // 마감일 기준 오름차순 정렬
    sort(v.begin(), v.end(), [](const Assignment& a, const Assignment& b) {
        return a.deadline < b.deadline;
    });

    priority_queue<int> pq; // 점수 기준 최대 힙
    int totalScore{ 0 };    // 얻을 수 있는 총 최대 점수
    int idx{ n - 1 };       // 역순 인덱스

    // 가장 큰 마감일 부터 역순으로 날짜 탐색
    for (int day = v.back().deadline; day > 0; --day)
    {
        // 현재 day 에 마감일에 해당되거나 그 이후인 과제 추가
        while (idx >= 0 && v[idx].deadline >= day)
        {
            pq.push(v[idx].score);
            --idx;
        }
        // 현재 마감일 기준 해결 가능한
        // 가장 높은 점수의 과제부터 해결
        if (!pq.empty())
        {
            totalScore += pq.top();
            pq.pop();
        }
    }

    cout << totalScore;


    return 0;
}
