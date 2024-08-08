#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 강의실 1374 PriorityQueue
// O( N logN )


struct Lecture {
    int start;
    int end;
};

// 시작 시간 기준 오름차순 비교자
bool cmp(const Lecture& a, const Lecture& b) 
{
    return a.start < b.start;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<Lecture> lectures(n);
    for (int i = 0; i < n; ++i)
    {
        int id;
        cin >> id >> lectures[i].start >> lectures[i].end;
    }

    // 강의 시작 시간 기준 오름차순
    sort(lectures.begin(), lectures.end(), cmp);

    // 강의 종료 시간 기준 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;

    // 첫 번째 강의 종료 시간 삽입
    pq.push(lectures[0].end);

    for (int i = 1; i < n; ++i)
    {
        // 기존 강의실을 사용할 수 있는가?
        if (pq.top() <= lectures[i].start)
        {
            // 강의실을 비움
            pq.pop();
        }
        pq.push(lectures[i].end);
    }

    // pq 의 크기가 필요한 강의실의 수
    cout << pq.size();


    return 0;
}
