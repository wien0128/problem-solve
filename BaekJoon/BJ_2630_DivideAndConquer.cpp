#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2630 Divide-and-Conquer
// 쿼드 트리를 재귀와 분할 정복으로 구현


// paper = 종이 색 정보 2차원 배열
// x, y = 현재 탐색을 시작할 위치
// srchSize = 현재 탐색 영역 크기
// white, blue = 흰, 파 종이 수 참조 변수
void cntColorPaper(const vector<vector<int>>& paper, int x, int y, int srchSize, int& white, int& blue)
{
    bool isSame{ true }; // 같은 색 = 자를 필요 없음
    int startColor{ paper[x][y] }; // 탐색 시작칸 색

    for (int i = x; i < x + srchSize && isSame; ++i)
    {
        for (int j = y; j < y + srchSize; ++j)
        {
            // 다른 색인가?
            if (paper[i][j] != startColor)
            {
                // 다르다.
                // 4분할 해야 함
                isSame = false;
                break;
            }
        }
    }

    if (isSame)
    {
        // 흰색 or 파란색 종이
        if (startColor == 0)
            ++white;
        else
            ++blue;
    }
    else
    {
        // 탐색 범위 재설정
        int newSrchSize = srchSize / 2;
        // 2사분면
        cntColorPaper(paper, x, y, newSrchSize, white, blue);
        // 1사분면
        cntColorPaper(paper, x, y + newSrchSize, newSrchSize, white, blue);
        // 3사분면
        cntColorPaper(paper, x + newSrchSize, y, newSrchSize, white, blue);
        // 4사분면
        cntColorPaper(paper, x + newSrchSize, y + newSrchSize, newSrchSize, white, blue);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> paper(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }

    int white{ 0 }, blue{ 0 };
    cntColorPaper(paper, 0, 0, n, white, blue);

    cout << white << "\n" << blue << "\n";


    return 0;
}
