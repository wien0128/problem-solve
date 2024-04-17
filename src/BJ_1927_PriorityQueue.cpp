#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

// 백준 1927 Priority Queue
// priority_queue<자료형, 구현체, 비교연산자> pq

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
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
