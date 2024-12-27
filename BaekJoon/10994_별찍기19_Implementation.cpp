#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using Board = vector<vector<char>>;

// 별찍기19 10994 Implementation
// O( n^2 )


// Solve 1
// 정사각형 별 패턴 그리기, 외부 -> 내부 순서로 그림
// {0,0} -> {2,2} -> {4,4} -> ...
void drawStars(Board& board, int curSize, int x, int y)
{
    // 현재 패턴 크기
    int len{ 4 * (curSize - 1) + 1 };

    for (int i = 0; i < len; ++i)
    {
        board[x][y + i] = '*';              // 상단
        board[x + len - 1][y + i] = '*';    // 하단
        board[x + i][y] = '*';              // 좌측
        board[x + i][y + len - 1] = '*';    // 우측
    }

    // 내부 패턴 시작 좌표로 재귀
    if (curSize > 1) drawStars(board, curSize - 1, x + 2, y + 2);
}

// Solve 2
// 중심으로부터의 거리 홀수(' '), 짝수(*) 그리기
// = 맨해튼 거리와 유사 = 격자 이동 거리
void drawStarsWithMath(Board& board, int n)
{
    int size = (n - 1) * 2;

    for (int i = -size; i <= size; ++i)
    {
        for (int j = -size; j <= size; ++j)
        {
            cout.put(max(abs(i), abs(j)) % 2 == 0 ? '*' : ' ');
        }
        cout.put('\n');
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int size{ 4 * (n - 1) + 1 };    // 전체 가로, 세로 크기
    Board board(size, vector<char>(size, ' '));

    drawStars(board, n, 0, 0);

    for (const auto& row : board)
    {
        cout << string(row.begin(), row.end()) << "\n";
    }
    cout << '\n';

    board = Board(size, vector<char>(size, ' '));

    drawStarsWithMath(board, n);

    return 0;
}
