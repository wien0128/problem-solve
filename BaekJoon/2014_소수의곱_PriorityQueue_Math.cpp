#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

// 소수의곱 2014 PriorityQueue
// 중복 계산과 저장을 방지하는 게 핵심
// O( N * K * logM)


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k, n;
    cin >> k >> n;

    // 최소 힙
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    vector<ll> primes(k);
    for (auto& p : primes)
    {
        cin >> p;
        pq.push(p);
    }

    ll cur{ 0 };
    while (n--)
    {
        cur = pq.top();
        pq.pop();

        for (const auto& p : primes)
        {   
            // 오버플로우 방지
            if (cur > LLONG_MAX / p) break;

            ll next = cur * p;
            pq.push(next);

            // 중복 계산 방지
            // 나누어 떨어진다면 이미 계산한 값
            if (cur % p == 0) break;
        }
    }

    cout << cur;


    return 0;
}
