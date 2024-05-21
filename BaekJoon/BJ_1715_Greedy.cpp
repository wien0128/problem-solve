#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using Cards = priority_queue<int, vector<int>, greater<int>>;

// 백준 1715 Greedy
// 우선순위 큐를 사용하면 간단한 문제
// 다만, 이게 왜 최적해인지는 모르겠다.
// Proof of Optimality of Huffman Coding와 유사하지만 이해는 못한..


int minCardsCompare(Cards& cards)
{
    int cost{ 0 };
    while (cards.size() > 1)
    {   
        // 가장 작은 값 두 개를 더해 push
        int first = cards.top();
        cards.pop();
        int second = cards.top();
        cards.pop();

        int newCard = first + second;
        cost += newCard;

        cards.push(newCard);
    }

    return cost;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    Cards cards;    // 오름차순 우선순위 큐
    for (int i = 0; i < n; ++i)
    {
        int card;
        cin >> card;
        cards.push(card);
    }

    cout << minCardsCompare(cards);

    
    return 0;
}
