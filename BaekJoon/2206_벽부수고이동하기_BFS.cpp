#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>

using namespace std;
using Map = vector<vector<int>>;
using Dist = vector<vector<vector<int>>>;

// 벽_부수고_이동하기 2206 BFS
// 뭐이리 어렵냐
// 벽을 부수고 간 상태와 부수지 않고 간 상태를 저장하는게 핵심


// 방향 벡터
constexpr pair<int, int> directions[] = {
    {-1, 0},    // 상
    {1, 0},     // 하
    {0, -1},    // 좌
    {0, 1}      // 우
};

// 최단 경로 찾기
int BFS(int n, int m, const Map& map)
{
    // 거리 벡터: [x][y][0] = 벽 부수지 않음, [x][y][1] = 벽 부숨
    // dist[x][y][wallStatus] = 해당 좌표까지의 거리 && -1 아닐 경우 방문한 적이 있음
    Dist dist(n, vector<vector<int>>(m, vector<int>(2, -1)));

    // q(x, y, wallStatus)
    queue<tuple<int, int, int>> q;

    // tuple이기에 emplace()로 삽입
    q.emplace(0, 0, 0); // (0, 0)에서 벽 부수지 않은 상태
    dist[0][0][0] = 1;  // 시작점 거리는 1

    while (!q.empty())
    {
        auto [x, y, wallStatus] = q.front();
        q.pop();

        // [n, m]에 도착한 경우
        if (x == n - 1 && y == m - 1)
        {
            return dist[x][y][wallStatus];
        }

        // 상하좌우 탐색
        for (const auto& [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;

            // 탐색 위치가 map 범위 내인 경우
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                int nextDist = dist[x][y][wallStatus] + 1;

                // 빈칸이면서 && 방문한 적이 없는 경우
                if (map[nx][ny] == 0 && dist[nx][ny][wallStatus] == -1)
                {
                    dist[nx][ny][wallStatus] = nextDist; // 방문 거리 입력
                    q.emplace(nx, ny, wallStatus);
                }
                // 벽이면서 && 한 번도 벽을 부순적이 없으며 && 방문한 적이 없는 경우
                else if (map[nx][ny] == 1 && wallStatus == 0 && dist[nx][ny][1] == -1)
                {
                    dist[nx][ny][1] = nextDist; // 벽을 부수고 간 거리 입력
                    q.emplace(nx, ny, 1);
                }
            }
        }
    }

    // [n, m]에 도달 못하는 경우
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Map map(n, vector<int>(m, 0));  // 0-based indexing
    for (int i = 0; i < n; ++i)
    {
        string in;  // 입력이 붙어서 들어오기에 string
        cin >> in;
        for (int j = 0; j < m; ++j)
        {
            map[i][j] = in[j] - '0'; // char -> int
        }
    }

    cout << BFS(n, m, map);


    return 0;
}
