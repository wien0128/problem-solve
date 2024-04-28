#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 백준 1780 Divide-and-Conquer
// 분할 정복 응용 문제


// 해당 영역 동일성 확인
bool isSame(const vector<vector<int>>& paper, int x, int y, int size)
{
    int firstValue{ paper[x][y] };
    for (int i = x; i < x + size; ++i)
    {
        for (int j = y; j < y + size; ++j)
        {
            if (paper[i][j] != firstValue)
            {
                return false;
            }
        }
    }
    return true;
}

// 9개 분할 트리
void nonaTree(vector<vector<int>>& paper, vector<int>& cnt, int x, int y, int size)
{
    // 해당 숫자 영역이 모두 같은가?
    if (isSame(paper, x, y, size))
    {
        // 같다.
        // 해당 값 카운트 증가
        cnt[paper[x][y] + 1]++;
        return;
    }

    int newSize{ size / 3 };

    // 9개 영역으로 나누어 탐색
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            // 그 다음 좌표로 재귀 호출
            nonaTree(paper, cnt, x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // n * n 벡터
    vector<vector<int>> paper(n, vector<int>(n));
    // { -1, 0, 1 } 저장 벡터
    vector<int> cnt(3, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> paper[i][j];
        }
    }

    nonaTree(paper, cnt, 0, 0, n);

    for (int it : cnt)
    {
        cout << it << "\n";
    }


    return 0;
}
