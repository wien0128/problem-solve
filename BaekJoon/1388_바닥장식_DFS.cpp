#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 바닥장식 1388 DFS
// 반복문을 통한 DFS
// O( n * m )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> floor(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));    // 방문 여부
    for (string& s : floor) cin >> s;

    int cnt{ 0 };   // 필요한 나무 판자 개수

    // 전체 타일 탐색
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // 중복 탐색 방지
            if (visited[i][j]) continue;

            visited[i][j] = true;   // 방문 처리
            ++cnt;

            // 행 탐색, 현재 행의 끝가지 같은 타일인지 확인
            if (floor[i][j] == '-')
            {
                int k = j + 1;
                while (k < m && floor[i][k] == '-')
                {
                    visited[i][k] = true;
                    ++k;
                }
            }
            // 열 탐색, 현재 열의 끝까지 같은 타일인지 확인
            else if (floor[i][j] == '|')
            {
                int k = i + 1;
                while (k < n && floor[k][j] == '|')
                {
                    visited[k][j] = true;
                    ++k;
                }
            }
        }
    }

    cout << cnt;


    return 0;
}
