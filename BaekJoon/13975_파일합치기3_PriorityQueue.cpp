#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

// 파일합치기3 13975 PriorityQueue
// O( N logN )


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

        // 최소힙
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        for (int i = 0; i < k; ++i)
        {
            ll f;
            cin >> f;
            pq.push(f);
        }

        ll totalCost{ 0 };  // 병합에 든 총 비용
        while (pq.size() > 1)
        {
            ll first = pq.top(); pq.pop();
            ll second = pq.top(); pq.pop();

            // 가장 작은 두 값을 병합
            ll merge = first + second;
            totalCost += merge; // 총 비용에 +
            pq.push(merge); // 병합한 값을 다시 push
        }

        cout << totalCost << "\n";
    }


    return 0;
}
