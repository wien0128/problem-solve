#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 백준 11000 Greedy
// 아이디어가 어려웠던 문제


struct Lecture {
    int start;
    int end;
};

bool cmp(const Lecture& a, const Lecture& b)
{
    return a.start < b.start;
}

int getCntClass(vector<Lecture>& lectures)
{
    // 강의 시작 시간 기준 오름차순
    ranges::sort(lectures, cmp);

    // 종료 시간 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;
    // 첫 번째 강의 종료 시간 push
    pq.push(lectures[0].end);
    
    for (size_t i = 1; i < lectures.size(); ++i)
    {
        // 가장 일찍 끝나는 강의실의 종료 시간 <= 현재 강의 시작 시간
        if (pq.top() <= lectures[i].start)
        {
            // 기존 강의실 사용 가능
            pq.pop();
        }
        // 새로운 강의의 종료 시간 push
        pq.push(lectures[i].end);
    }

    // 현재 사용 중인 강의실 수 == 필요한 강의실 수
    return pq.size();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<Lecture> lectures(n);
    for (auto& it : lectures)
    {
        cin >> it.start >> it.end;
    }

    cout << getCntClass(lectures);

    
    return 0;
}
