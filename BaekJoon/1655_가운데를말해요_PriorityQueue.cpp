#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 가운데를말해요 1655 PriorityQueue
// 아이디어가 좀 어려운 문제
// O( NlogN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 최대 힙, 중간값 이하의 값들
    priority_queue<int> maxHeap;
    // 최소 힙, 중간값 이상의 값들
    priority_queue<int, vector<int>, greater<>> minHeap;

    int n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;

        // 1. maxHeap 의 크기는 minHeap 의 크기와 같거나 하나 더 크게 유지
        // 2. maxHeap.top() 은 minHeap.top() 보다 작거나 같게
        // 3. (1), (2)에 위배될 시 max/minHeap.top() 값을 반대로 옮김

        if (maxHeap.empty() || x <= maxHeap.top())
        {
            maxHeap.emplace(x);
        }
        else
        {
            minHeap.emplace(x);
        }

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.emplace(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.emplace(minHeap.top());
            minHeap.pop();
        }

        cout << maxHeap.top() << "\n";
    }


    return 0;
}
