#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

// 백준 11279 Priority Queue
// 최대힙 구현 문제이긴 하지만 priority_queue가 최대 힙으로 이미 구현되어 있으니깐..

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<ll> pq;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        if (x == 0)
        {
            if (pq.empty())
            {
                cout << 0 << "\n";
                continue;
            }
          
            cout << pq.top() << "\n";
            pq.pop();
        }
        else
        {
            pq.push(x);
        }
    }

    return 0;
}
