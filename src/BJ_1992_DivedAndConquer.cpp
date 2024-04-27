#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 백준 1992 Divide-and-Conquer


// 쿼드 트리 분할 정복 구현
string quadTree(const vector<string>& video, int x, int y, int size)
{
    bool isSame{ true };
    for (int i = x; i < x + size && isSame; ++i)
    {
        for (int j = y; j < y + size; ++j)
        {
            // 현재 영역의 값이 동일한가?
            if (video[i][j] != video[x][y])
            {
                isSame = false;
                break;
            }
        }
    }

    // 모든 값이 같은가?
    if (isSame)
    {
        // 같다.
        // 해당 값(1, 0) 반환
        return string(1, video[x][y]);
    }
    else
    {
        // 다르다.
        // 4분할 한다.
        int newSize = size / 2;
        string topL = quadTree(video, x, y, newSize); // 2사분면
        string topR = quadTree(video, x, y + newSize, newSize); // 1사분면
        string bottomL = quadTree(video, x + newSize, y, newSize); // 3사분면
        string bottomR = quadTree(video, x + newSize, y + newSize, newSize); // 4사분면

        // 4개 영역 괄호로 묶어서 반환
        return "(" + topL + topR + bottomL + bottomR + ")";
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> video(n);
    for (int i = 0; i < n; i++)
    {
        cin >> video[i];
    }

    cout << quadTree(video, 0, 0, n) << "\n";


    return 0;
}
