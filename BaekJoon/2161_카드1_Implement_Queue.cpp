#include <iostream>
#include <queue>

using namespace std;

// 카드1 2161 Implement, queue
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    queue<int> cards;
    for (int i = 1; i <= n; ++i)
    {
        cards.push(i);
    }

    while (cards.size() > 1)
    {
        cout << cards.front() << " ";
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }

    cout << cards.front();


    return 0;
}
