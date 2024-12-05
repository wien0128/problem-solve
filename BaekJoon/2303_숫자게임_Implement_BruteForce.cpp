#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 숫자게임 2303 Implement, BruteForce
// O( n )
// 조합 계산의 경우 O(10)으로 상수값을 지님


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 우승자 인덱스, 최대 점수
    int res{ 0 }, maxScore{ 0 };
    
    // 각 참가자마다 반복
    for (int i = 1; i <= n; ++i)
    {
        // 카드 5장 벡터에 입력
        vector<int> cards(5);
        for (int& c : cards) cin >> c;

        // 현재 참가자의 최대 점수
        int curMaxScore{ 0 };
        // 5C3 조합 선택
        for (int a = 0; a < 5; ++a)
        {
            for (int b = a + 1; b < 5; ++b)
            {
                for (int c = b + 1; c < 5; ++c)
                {
                    curMaxScore = max(curMaxScore, (cards[a] + cards[b] + cards[c]) % 10);
                }
            }
        }

        // 최대값 갱신, 우승자 인덱스 입력
        if (curMaxScore >= maxScore)
        {
            maxScore = curMaxScore;
            res = i;
        }
    }

    cout << res;


    return 0;
}
