#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Box = vector<vector<int>>;

// 백준 7576 multisource BFS (다중 출발점 BFS)
// 익은 토마토를 기준으로 BFS 돌리는 게 핵심
// 일수를 세기 위해 현재 레벨의 노드를 탐색하는 것도 핵심
// 여러모로 까다로운 문제


// 방향 벡터
constexpr pair<int, int> directions[] = {
    {-1, 0},    // 상
    {1, 0},     // 하
    {0, -1},    // 좌
    {0, 1}      // 우
};

class TomatoBox {
private:
    int n, m;   // 세로, 가로
    int unripe; // 익지 않은 토마토 개수
    Box box;    // n * m
    queue<pair<int, int>> q;
public:
    TomatoBox(int n, int m) : n(n), m(m), unripe(0), box(n, vector<int>(m)) {}

    // 토마토 삽입 + 상태 구분
    void insertTomato(int x, int y, int state)
    {
        box[x][y] = state;
        if (state == 1) // 익은 토마토 push
        {
            q.push({ x, y });
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
                auto [x, y] = q.front();
                q.pop();

                for (const auto& [dx, dy] : directions)
                {
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    // 탐새 범위 예외처리
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    // 익지 않은 토마토일 경우
                    if (box[nx][ny] == 0)
                    {
                        q.push({ nx, ny });
                        box[nx][ny] = 1; // 익힘
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

    int m, n;
    cin >> m >> n;

    TomatoBox box(n, m);
    int state;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            //  1 = 익은 토마토
            //  0 = 익지 않은 토마토
            // -1 = 비어있는 칸
            cin >> state;
            box.insertTomato(i, j, state);
        }
    }

    cout << box.BFS();


    return 0;
}
