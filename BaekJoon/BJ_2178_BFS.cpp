#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// 백준 2178 BFS
// 최단 경로 길 찾기 기본 문제
// 최단 경로는 BFS가 구현이 쉽다
// 최단 경로의 수는 DFS + DP로


// 방향 벡터
constexpr pair<int, int> directions[] = {
    {0, -1},    // 상
    {0, 1},     // 하
    {-1, 0},    // 좌
    {1, 0}      // 우
};

class Maze {
private:
    const vector<string>& maze; // 미로
    int n, m;                   // n * m
    vector<vector<int>> path;   // (n, m)까지의 경로 기록
public:
    Maze(const vector<string>& maze, int n, int m) 
        : maze(maze), n(n), m(m), path(n, vector<int>(m, 0)) {}

    // DFS
    int BFS()
    {
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        path[0][0] = 1;

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (const auto& [dx, dy] : directions)
            {
                int nx = x + dx;
                int ny = y + dy;

                // 탐색 범위 유효성 체크
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                // 길이 있고 방문하지 않았다면
                if (maze[nx][ny] == '1' && path[nx][ny] == 0)
                {
                    q.emplace(nx, ny);
                    path[nx][ny] = path[x][y] + 1;  // 방문 순서
                }
            }
        }
        return path[n - 1][m - 1];  // 0-based index
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> maze(n); // 붙은 입력이기에 string
    for (int i = 0; i < n; ++i)
    {
        cin >> maze[i];
    }

    Maze res(maze, n, m);
    cout << res.BFS();


    return 0;
}
