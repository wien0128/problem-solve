#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 사탕게임 3085 Brute Force


// 사탕게임 클래스 O(N^3)
class CandyGame {
private:
    int n;                  // 보드 크기
    vector<string> board;   // 보드

    // (x, y) 주변 최대로 연속된 사탕의 길이 계산 후 반환
    int findMaxLength(int x, int y) const {
        int maxLength{ 1 };

        // 행 검사
        int cnt{ 1 };
        for (int j = 1; j < n; ++j)
        {
            // 왼쪽 사탕과 같은 색인가?
            if (board[x][j] == board[x][j - 1])
            {
                ++cnt;
            }
            else
            {
                cnt = 1;
            }
            maxLength = max(maxLength, cnt);
        }

        // 열 검사
        cnt = 1;
        for (int i = 1; i < n; ++i)
        {
            // 위쪽 사탕과 같은 색인가?
            if (board[i][y] == board[i - 1][y])
            {
                ++cnt;
            }
            else
            {
                cnt = 1;
            }
            maxLength = max(maxLength, cnt);
        }

        return maxLength;
    }

public:
    CandyGame(int n, vector<string>& board) : n(n), board(board) {}

    // 최대로 연속된 사탕의 길이
    int getMaxCandies() {
        int maxLength{ 1 };

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 오른쪽 사탕 교환
                if (j + 1 < n)
                {
                    swap(board[i][j], board[i][j + 1]);
                    // 교환한 위치와 교환전 위치의 최대 길이 계산
                    maxLength = max(maxLength, findMaxLength(i, j));
                    maxLength = max(maxLength, findMaxLength(i, j + 1));
                    swap(board[i][j], board[i][j + 1]); // 원산복구
                }
                // 아래쪽 사탕 교환
                if (i + 1 < n)
                {
                    swap(board[i][j], board[i + 1][j]);
                    // 교환한 위치와 교환전 위치의 최대 길이 계산
                    maxLength = max(maxLength, findMaxLength(i, j));
                    maxLength = max(maxLength, findMaxLength(i + 1, j));
                    swap(board[i][j], board[i + 1][j]); // 원상복구
                }
            }
        }

        return maxLength;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> board(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }
    
    CandyGame game(n, board);
    cout << game.getMaxCandies();

    return 0;
}
