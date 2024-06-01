#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

// 백준 2667 DFS
// 인접 행렬을 받아 DFS로 집 찾기 문제
// 아이디어는 금방 알았지만 구현이 어려웠다

// 방향 벡터
const vector<pair<int, int>> directions = {
    {-1, 0},    // 상
    {1, 0},     // 하
    {0, -1},    // 좌
    {0, 1}      // 우
};

class AdjMatrix {
private:
    int n;                          // 지도 크기 n*n
    vector<string> map;             // 지도
    vector<vector<bool>> visited;   // 방문 여부

    // 단지 내 집 수 계산 반복문 DFS
    void DFS(int x, int y, int& cnt)
    {
        stack<pair<int, int>> s;
        s.push({ x, y });
        visited[x][y] = true;   // 현재 집 방문 표시

        while (!s.empty())
        {
            auto [x, y] = s.top();
            s.pop();
            cnt++;  // 집 수 증가

            // [x, y] 기준 상하좌우 탐색
            for (const auto& [dx, dy] : directions)
            {
                int nx = x + dx;
                int ny = y + dy;
                
                // map 초과 예외
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                // 집이 있고 방문하지 않았다면
                if (map[nx][ny] == '1' && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    s.push({ nx, ny });
                }
            }
        }
    }
public:
    AdjMatrix(int n, const vector<string>& inputMap)
        : n(n), map(inputMap), visited(n, vector<bool>(n, false)) {}

    // 단지 수와 집 수 계산 후 반환
    vector<int> findComplex()
    {
        vector<int> complexes;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 집이 있고 방문하지 않았다면
                if (map[i][j] == '1' && !visited[i][j])
                {
                    int cnt{ 0 };   // 단지 내 집 수
                    DFS(i, j, cnt);
                    complexes.push_back(cnt);
                }
            }
        }
        ranges::sort(complexes);    // 집의 수 오름차순

        return complexes;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 입력에 띄어쓰기가 없기에 string으로 받기
    vector<string> inputMap(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> inputMap[i];
    }

    AdjMatrix m(n, inputMap);
    vector<int> res = m.findComplex();

    cout << res.size() << "\n"; // 단지 수
    for (const int& cmpx : res) // 단지 별 집의 수
    {
        cout << cmpx << "\n";
    }


    return 0;
}
