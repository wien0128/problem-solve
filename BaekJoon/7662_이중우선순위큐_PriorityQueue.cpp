#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
using ll = long long;

// 이중우선순위큐 7662 PriorityQueue
// 좀 어려웠다;
// O( T * K logN )


// 이중 우선순위 큐
class DualPriorityQueue {
private:
    priority_queue<ll> maxHeap;    // 최대 힙
    priority_queue<ll, vector<ll>, greater<ll>> minHeap; // 최소 힙
    unordered_map<ll, ll> cntMap;    // 숫자 카운터

    // 힙 최상단에 삭제된 요소가 있을 경우 삭제
    void cleanHeap(auto& heap) {
        while (!heap.empty() && cntMap[heap.top()] == 0)
        {
            heap.pop();
        }
    }

    // 힙 최상단 값 삭제 메서드
    void deleteTop(auto& heap) {
        cleanHeap(heap);
        if (!heap.empty())
        {
            --cntMap[heap.top()];
            heap.pop();
        }
    }
public:
    // num 을 최대힙, 최소힙에 삽입
    void insert(ll num)
    {
        maxHeap.push(num);
        minHeap.push(num);
        ++cntMap[num];
    }

    // 최대값 삭제
    void deleteMax()
    {
        deleteTop(maxHeap);
    }

    // 최소값 삭제
    void deleteMin()
    {
        deleteTop(minHeap);
    }

    // 결과 반환
    // @return "최대값 최소값" or "EMPTY" 문자열 반환
    string getRes()
    {
        cleanHeap(maxHeap);
        cleanHeap(minHeap);

        if (maxHeap.empty() || minHeap.empty())
        {
            return "EMPTY";
        }
        return to_string(maxHeap.top()) + " " + to_string(minHeap.top());
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int k;
        cin >> k;

        DualPriorityQueue dpq;

        for (int i = 0; i < k; ++i)
        {
            char cmd;   // 명령어
            ll num;    // 숫자
            cin >> cmd >> num;

            if (cmd == 'I') // 숫자 삽입
            {
                dpq.insert(num);
            }
            else if (cmd == 'D') // 숫자 삭제
            {
                if (num == 1) // 최대값 삭제
                {
                    dpq.deleteMax();
                }
                else if (num == -1) // 최소값 삭제
                {
                    dpq.deleteMin();
                }
            }
        }

        cout << dpq.getRes() << "\n";
    }


    return 0;
}
