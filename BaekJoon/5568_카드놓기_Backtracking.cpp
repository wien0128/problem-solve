#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

// 카드놓기 5568 Backtracking
// DFS를 이용한 백트래킹 방법


// 조합 생성
void getCombination(const vector<int>& cards, int k, unordered_set<string>& res,
    vector<bool>& visited, string curNum)
{
    // k개를 골랐으면 추가
    if (k == 0)
    {
        res.insert(curNum);
        return;
    }

    // 모든 카드에 대해 순회
    for (size_t i = 0; i < cards.size(); ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            getCombination(cards, k - 1, res, visited, curNum + to_string(cards[i]));
            visited[i] = false; // 백트래킹
        }
    }
}

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

    unordered_set<string> res;  // 중복 불가
    vector<bool> visited(n, false); // 방문 여부

    getCombination(cards, k, res, visited, "");

    // 중복되지 않은 조합의 개수 출력
    cout << res.size();


    return 0;
}
