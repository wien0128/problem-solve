#include <iostream>
#include <queue>

using namespace std;

// 크리스마스선물 14235 PriorityQueue
// O( N logM )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> pq;

    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;

        if (a == 0) // 아이들을 만났다면
        {
            if (pq.empty()) // 줄 선물이 없다면
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else   // 거점지에서 선물 충전
        {
            for (int j = 0; j < a; ++j)
            {
                int x;
                cin >> x;
                pq.push(x);
            }
        }
    }


    return 0;
}
