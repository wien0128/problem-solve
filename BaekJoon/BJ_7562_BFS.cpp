#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 백준 7562 BFS
// 이동 방향 빼고는 비슷한 최단 거리 구하기 문제


// 나이트 이동 방향 벡터
constexpr pair<int, int> directions[8] = {
    {1, 2}, {2, 1}, {2, -1}, {1, -2}, // 5시, 4시, 2시, 1시
    {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} // 11시, 10시, 8시, 7시
};

int BFS(int l, pair<int, int> start, pair<int, int> end)
{
    // 체스판 + 방문 여부 + 이동 횟수
    vector<vector<int>> visited(l, vector<int>(l, 0));
    queue<pair<int, int>> q;

    q.push(start);
    visited[start.first][start.second] = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        // 목표 위치에 도달 시 이동 횟수 반환
        if (make_pair(x, y) == end)
        {
            return visited[x][y] - 1;
        }

        for (const auto& [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;

            // 유효 범위 확인
            if (nx < 0 || nx >= l || ny < 0 || ny >= l) 
                continue;

            // 방문한 적이 없다면
            if (visited[nx][ny] == 0)
            {
                // 새로운 위치 큐 push & 방문 표시
                q.push({ nx, ny });
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int l;
        cin >> l;

        pair<int, int> start, end;
        cin >> start.first >> start.second; // 시작 위치
        cin >> end.first >> end.second;     // 도착 위치

        cout << BFS(l, start, end) << "\n";
    }

    return 0;
}
