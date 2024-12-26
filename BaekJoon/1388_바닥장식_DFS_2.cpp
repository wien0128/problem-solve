#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 바닥장식 1388 DFS
// 반복문을 통한 DFS v2
// visited 배열 필요 없음, 현재 상태의 연속 여부만 확인하여 판단
// O( n * m )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> floor(n);
    for (string& s : floor) cin >> s;

    int cnt{ 0 };   // 필요한 나무 판자 개수

    // 전체 타일 탐색
    // 이전 타일이 현재 타일과 다르다면 새 타일이 필요 
    // = 연속성 확인
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // 행 탐색, 현재 행과 이전 행 비교
            if (floor[i][j] == '-')
            {
                if (j == 0 || floor[i][j - 1] != '-') ++cnt;
            }
            // 열 탐색, 현재 열과 이전 열 비교
            else if (floor[i][j] == '|')
            {
                if (i == 0 || floor[i - 1][j] != '|') ++cnt;
            }
        }
    }

    cout << cnt;


    return 0;
}
