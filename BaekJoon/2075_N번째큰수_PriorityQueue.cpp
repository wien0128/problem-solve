#include <iostream>
#include <queue>

using namespace std;

// N번째큰수 2075 PriorityQueue
// 메모리 관리가 관건
// O( N^2 logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n * n; ++i)
    {
        int x;
        cin >> x;
        pq.push(x);

        // n 개의 숫자만 남기기 위해 pop
        if (pq.size() > n) pq.pop();
    }

    cout << pq.top();


    return 0;
}
