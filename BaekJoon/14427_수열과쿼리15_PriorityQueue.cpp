#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

// 수열과쿼리15 14427 PriorityQueue
// O( N logN + M logN )


class MinHeap {
private:
    // 최소 힙, { 값, 인덱스 }
    priority_queue<pii, vector<pii>, greater<>> pq;
    // 원본 배열
    vector<int> arr;
public:
    MinHeap(const vector<int>& v) : arr(v) 
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            pq.emplace(arr[i], i + 1); // 1-based index
        }
    }

    // 배열&최소힙 값 업데이트
    void update(int idx, int val)
    {
        arr[idx] = val;
        pq.emplace(val, idx + 1);
    }

    // 현재 최소값의 인덱스 반환
    // Lazy Propagation (느린 갱신)
    int query()
    {
        // 최소 힙의 최상단 요소가 현재 배열의 값과
        // 일치하지 않으면 pop
        // 최신 상태의 { 값, 인덱스 }을 보장하기 위함
        while (pq.top().first != arr[pq.top().second - 1])
        {
            pq.pop();
        }
        return pq.top().second;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;

    vector<int> arr(n);
    for (int& x : arr)
    {
        cin >> x;
    }

    MinHeap minHeap(arr);

    cin >> m;
    
    while (m--)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 2)
        {
            cout << minHeap.query() << "\n";
        }
        else
        {
            int idx, val;
            cin >> idx >> val;
            minHeap.update(idx - 1, val);
        }
    }


    return 0;
}
