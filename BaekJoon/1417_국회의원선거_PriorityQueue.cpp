#include <iostream>
#include <queue>

using namespace std;

// 국회의원선거 1417 PriorityQueue
// O( NlogN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, dasom;
    cin >> n >> dasom;

    priority_queue<int> pq;     // 나머지 후보들의 득표수
    for (int i = 1; i < n; ++i)
    {
        int vote;
        cin >> vote;
        pq.push(vote);
    }

    int res{ 0 };   // 매수 횟수

    while (!pq.empty() && pq.top() >= dasom)
    {
        int maxVote = pq.top(); // 현재 가장 많은 득표자의 수
        pq.pop();               
        --maxVote;              // 최대 득표자의 수 감소
        ++dasom;                // 다솜이 득표 수 증가
        ++res;                  // 매수 횟수 증가
        pq.push(maxVote);       
    }

    cout << res;


    return 0;
}
