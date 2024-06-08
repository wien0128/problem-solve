#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using Box = vector<vector<vector<int>>>;

// 백준 7569 multisource BFS (다중 출발점 BFS)
// 7576번의 3차원 버전


// 방향 벡터
// C++11과 C++14에서는 constexpr와 tuple은 같이 못 씀
constexpr tuple<int, int, int> directions[] = {
    {-1, 0, 0},     // 위
    {1, 0, 0},      // 아래
    {0, -1, 0},     // 앞
    {0, 1, 0},      // 뒤
    {0, 0, -1},     // 좌
    {0, 0, 1},      // 우
};

class TomatoBox {
private:
    int n, m, h;    // 세로, 가로, 높이
    int unripe;     // 익지 않은 토마토 개수
    Box box;        // h * n * m
    queue<tuple<int, int, int>> q;
public:
    TomatoBox(int h, int n, int m) 
        : h(h), n(n), m(m), unripe(0), box(h, vector<vector<int>>(n, vector<int>(m))) {}

    // 토마토 삽입 + 상태 구분
    void insertTomato(int z, int x, int y, int state)
    {
        box[z][x][y] = state;
        if (state == 1) // 익은 토마토 push
        {
            q.push({ z, x, y });
        }
        else if (state == 0) // ++익지 않은 토마토
        {
            ++unripe;
        }
    }
    
    // BFS
    int BFS()
    {
        if (unripe == 0) return 0; // 익은 토마토가 없으면 0 반환

        int days{ 0 }; // 모든 토마토가 익기까지 걸리는 일수

        while (!q.empty())
        {
            int size = q.size(); // 현재 레벨의 익은 토마토(노드) 개수

            // 현재 레벨에서 익히기 가능한 모든 토마토들을 익히기
            // 동시 처리를 위함
            while (size--)
            {
                auto [z, x, y] = q.front();
                q.pop();

                for (const auto& [dz, dx, dy] : directions)
                {
                    int nz = z + dz;
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    // 탐색 범위 예외처리
                    if (nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    // 익지 않은 토마토일 경우
                    if (box[nz][nx][ny] == 0)
                    {
                        q.push({ nz, nx, ny });
                        box[nz][nx][ny] = 1; // 익힘
                        --unripe;
                    }
                }
            }
            ++days;
        }

        // 익지 않은 토마토가 남아있다면 -1
        return (unripe > 0) ? -1 : days - 1;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n, h;
    cin >> m >> n >> h;

    TomatoBox box(h, n, m);
    int state;

    for (int z = 0; z < h; ++z)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                //  1 = 익은 토마토
                //  0 = 익지 않은 토마토
                // -1 = 비어있는 칸
                cin >> state;
                box.insertTomato(z, i, j, state);
            }
        }
    }

    cout << box.BFS();


    return 0;
}
