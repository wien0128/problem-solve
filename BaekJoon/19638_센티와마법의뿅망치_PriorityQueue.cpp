#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

// 센티와마법의뿅망치 19638 PriorityQueue
// O( (N + T)logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, h, t;
    cin >> n >> h >> t;

    // 거인들 키 최대 힙
    priority_queue<ll> giants;
    for (int i = 0; i < n; ++i)
    {
        ll height;
        cin >> height;
        giants.emplace(height);
    }

    int hammerCnt{ 0 }; // 뿅망치 사용한 횟수
    // 뿅망치 사용 가능 횟수 && 가장 큰 거인의 키가 센티의 키보다 크거나 같을 때까지
    while (t-- > 0 && giants.top() >= h)
    {
        ll tallest = giants.top();
        giants.pop();

        // 키가 1인 경우 그대로 삽입
        if (tallest == 1)
        {
            giants.push(1);
        }
        else
        {
            // 가장 큰 거인의 키를 절반 후 삽입
            giants.push(tallest / 2);
        }
        // 뿅망치 사용한 횟수 증가
        ++hammerCnt;
    }

    // 모든 거인의 키가 h 보다 작다면
    if (giants.top() < h)
    {
        cout << "YES\n" << hammerCnt;
    }
    else
    {
        cout << "NO\n" << giants.top();
    }


    return 0;
}
