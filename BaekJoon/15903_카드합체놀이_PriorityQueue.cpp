#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

// 카드합체놀이 15903 PriorityQueue
// 그리디하게 생각하면 쉽다, 자료형 주의
// O( (n + m)logn )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 최소 힙
    priority_queue<ll, vector<ll>, greater<ll>> cards;
    for (int i = 0; i < n; ++i)
    {
        ll a;
        cin >> a;
        cards.push(a);
    }

    // m 번 x + y 수행
    for (int i = 0; i < m; ++i)
    {
        ll x = cards.top(); cards.pop();
        ll y = cards.top(); cards.pop();

        ll newCard = x + y;
        cards.push(newCard);
        cards.push(newCard);
    }

    ll sum{ 0 }; // 최종 카드들의 합
    while (!cards.empty())
    {
        sum += cards.top();
        cards.pop();
    }

    cout << sum;


    return 0;
}
