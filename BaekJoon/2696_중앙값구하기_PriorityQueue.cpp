#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 중앙값구하기 2696 PriorityQueue
// 1655번과 같은 아이디어를 공유하는 문제
// 다만, 출력이 조금 까다롭다.
// O( NlogN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;


    while (T--)
    {
        int M;
        cin >> M;

        // 중앙값 저장 벡터
        vector<int> res;
        res.reserve((M + 1) / 2);
        // 최대 힙, 중앙값 이하 값
        priority_queue<int> maxHeap;
        // 최소 힙, 중앙값 이상 값
        priority_queue<int, vector<int>, greater<>> minHeap;

        for (int i = 1; i <= M; ++i)
        {
            int num;
            cin >> num;

            // 1. maxHeap 의 크기는 minHeap 의 크기와 같거나 하나 더 크게 유지
            // 2. maxHeap.top() 은 minHeap.top() 보다 작거나 같게
            // 3. (1), (2)에 위배될 시 max/minHeap.top() 값을 반대로 옮김

            if (maxHeap.empty() || num <= maxHeap.top())
            {
                maxHeap.emplace(num);
            }
            else
            {
                minHeap.emplace(num);
            }

            // 밸런싱
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

            // 1-based index, 홀수 번째 입력마다 중앙값 저장
            if (i & 1) // == (i % 2 == 1)
            {
                res.push_back(maxHeap.top());
            }
        }

        cout << res.size() << "\n";
        for (int i = 0; i < res.size(); ++i)
        {
            if (i > 0 && i % 10 == 0)   // 줄바꿈
            {
                cout << "\n";
            }
            cout << res[i] << " ";
        }
        cout << "\n";
    }


    return 0;
}
