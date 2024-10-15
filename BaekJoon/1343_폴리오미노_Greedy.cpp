#include <iostream>
#include <string>

using namespace std;

// 폴리오미노 1343 Greedy
// '.' 구분에 따른 예외 처리가 까다로운 문제
// O( N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string board;
    cin >> board;

    string res;
    res.reserve(board.length());
    // 'X' 개수 카운터
    int cntX{ 0 };

    // X를 AAAA 또는 BB로 치환하는 람다 함수
    // 사전순으로 앞선 답이어야 하기에 A부터 추가
    auto XtoAB = [&res](int cnt) {
        // append(개수, 문자), 개수만큼 문자 추가
        res.append((cnt / 4) * 4, 'A');
        res.append(cnt % 4, 'B');
        };

    for (char &c : board)
    {
        // '.'을 만날때마다 res에 이때까지의 모든 'X' 치환
        if (c == 'X')
        {
            ++cntX;
        }
        else
        {
            // X가 홀수개라면 표현 불가
            if (cntX & 1) return cout << "-1", 0;
            XtoAB(cntX);
            res += '.';
            cntX = 0;
        }
    }

    // X가 홀수개라면 표현 불가
    if (cntX & 1) return cout << "-1", 0;
    // 마지막 '.' 이후 남은 'X'에 대해 처리
    XtoAB(cntX);

    cout << res;


    return 0;
}
