#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

// 백준 16928 BFS
// 아이디어 떠올리기가 까다로웠음


void BFS(const array<int, 101>& board)
{
    array<int, 101> visited;   // 방문 여부 + 이동 횟수 벡터
    visited.fill(-1);
    queue<int> q;

    // 1번 칸에서 시작
    q.push(1);
    visited[1] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // 100번 칸에 도달한다면
        if (cur == 100)
        {
            cout << visited[cur];
            return;
        }

        // 주사위 결과에 따른 다음 위치 모두 탐색
        for (int dice = 1; dice <= 6; ++dice)
        {
            int next = cur + dice;

            if (next <= 100)
            {
                // 사다리 혹은 뱀 타고 이동한 곳
                next = board[next];

                // 방문하지 않은 위치라면
                if (visited[next] == -1)
                {
                    visited[next] = visited[cur] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 입력에 따른 1차원 벡터
    array<int, 101> board;
    for (int i = 1; i <= 100; ++i)
    {
        board[i] = i;
    }

    // 사다리 x -> y
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }
    // 빼ㅐ앰 u -> y
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    BFS(board);

    return 0;
}
