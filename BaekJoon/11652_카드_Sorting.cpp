#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// 카드 11652 Sorting
// O( N logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> cards(n);
    for (ll& card : cards)
    {
        cin >> card;
    }

    sort(cards.begin(), cards.end());

    // 최다 빈도 카드
    ll freqCard = cards[0];
    // 최다 빈도 카드 등장 횟수, 현재 카드 등장 횟수
    int maxCnt{ 1 }, curCnt{ 1 };

    for (int i = 1; i < n; ++i)
    {
        // 연속으로 같은 숫자 카드가 있다면
        if (cards[i] == cards[i - 1])
        {
            // 현재 카드 등장 횟수 증가
            ++curCnt;
        }
        else
        {
            // 더 많이 등장한 카드가 있다면 갱신
            if (curCnt > maxCnt)
            {
                maxCnt = curCnt;
                freqCard = cards[i - 1];
            }
            curCnt = 1;
        }
    }

    // 마지막 카드의 빈도 수 비교
    // [1 2 2 3 3 3]와 같은 경우 필요
    if (curCnt > maxCnt)
    {
        freqCard = cards[n - 1];
    }

    cout << freqCard;


    return 0;
}
