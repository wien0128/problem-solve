#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 아이들과선물상자 23757 PriorityQueue
// O( NlogN + MlogN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 선물 상자들 속 선물의 개수 최대 힙 
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i)
    {
        int gift;
        cin >> gift;
        pq.push(gift);
    }

    for (int i = 0; i < m; ++i)
    {
        int needs; // 원하는 선물 개수
        cin >> needs;

        // 선물이 없거나, 최대 선물 보유 상자가 니즈 보다 작다면
        if (pq.empty() || pq.top() < needs)
        {
            cout << 0; 
            return 0;
        }

        // 남은 선물 개수 삽입
        pq.push(pq.top() - needs);
        pq.pop();
    }

    cout << 1;


    return 0;
}
