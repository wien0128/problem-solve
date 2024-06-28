#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

// 카드놓기 5568 Backtracking
// next_permutation으로 직접 순열 생성 방법
// 불필요한 연산이 많다.


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> cards(n);
    for (auto& c : cards)
    {
        cin >> c;
    }

    sort(cards.begin(), cards.end());   // 오름차순 필수

    unordered_set<string> res;  // 중복 X
    do
    {
        string tmp;
        for (int i = 0; i < k; ++i)
        {
            tmp += to_string(cards[i]);
        }
        res.insert(tmp);    // k개 고른 순열 삽입
    } while (next_permutation(cards.begin(), cards.end())); // 다음 순열 생성

    cout << res.size(); // 순열의 개수 출력


    return 0;
}
