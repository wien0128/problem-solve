#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 백준 9663 BackTracking
// 대각선 좌표 검사
// (X, Y), (A, B) -> (X - A = Y - B) 
// 쉽지 않다..

// 퀸 배치 유효성 검사
bool isValid(const vector<int>& board, int row)
{
    for (int i = 0; i < row; i++)
    {
        // 같은 열 또는 대각선 상에 있는지 검사
        if (board[i] == board[row] || abs(board[row] - board[i]) == row - i)
        {
            return false;
        }
    }
    return true;
}

// 퀸 배치 재귀 함수
void nQueen(int row, int n, vector<int>& board, int& res)
{
    if (row == n)
    {
        res++; // 모든 행에 퀸 배치 시

        /*
        cout << "<TEST " << res << ">\n";
        for (int i = 0; i < board.size(); i++)
        {
            cout << "[" << i << ", " << board[i] << "]\n";
        }
        cout << '\n';
        */

        return;
    }
    for (int i = 0; i < n; i++)
    {
        board[row] = i; // 현재 행에 퀸 배치
        if (isValid(board, row)) // 유효한가?
        {
            // 다음 행 재귀 호출
            nQueen(row + 1, n, board, res);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, res{ 0 };
    cin >> n;

    vector<int> board(n);

    nQueen(0, n, board, res);

    cout << res;


    return 0;
}
