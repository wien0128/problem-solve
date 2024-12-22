#include <iostream>
#include <vector>

using namespace std;

// 빙고 2578 Implementation
// O( 1 )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> pos(26); // 빙고판 0-based
    vector<int> row(5), col(5);     // 행, 열 카운트
    int diag1{ 0 }, diag2{ 0 };     // 대각선 카운트

    for (int i = 0, num; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> num;             // 빙고판 숫자
            pos[num] = { i, j };    // 숫자의 좌표 저장
        }
    }

    // 사회자가 부른 횟수, 빙고 개수
    int callCnt{ 0 }, bingo{ 0 };

    for (int k = 0, num; k < 25; ++k)
    {
        cin >> num; // 사회자가 부른 수
        ++callCnt;  // 부른 횟수 증가

        auto [i, j] = pos[num];     // 숫자 좌표
        if (++row[i] == 5) ++bingo; // 해당 행 숫자 카운트
        if (++col[j] == 5) ++bingo; // 해당 열 숫자 카운트
        if (i == j && ++diag1 == 5) ++bingo;        // "\" 대각선 카운트
        if (i + j == 4 && ++diag2 == 5) ++bingo;    // "/" 대각선 카운트

        // 빙고가 3개 이상이라면 부른 횟수 출력 후 종료
        if (bingo >= 3)
        {
            cout << callCnt << "\n";
            return 0;
        }
    }


    return 0;
}
