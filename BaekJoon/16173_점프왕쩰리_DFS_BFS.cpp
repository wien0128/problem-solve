#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 점프왕쩰리 16173 DFS, BFS
// 간단한 그래프 탐색 문제
// O( n^2 )


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 보드 초기화
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    // 시작점이 0이면 즉시 종료
    if (board[0][0] == 0) 
    {
        cout << "Hing"; 
        return 0;
    }

    // DFS 용 스택, 방문 벡터
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    stack<pair<int, int>> st;
    st.emplace(0, 0);
    visited[0][0] = true;

    // DFS
    while (!st.empty())
    {
        auto [x, y] = st.top();
        st.pop();

        // 현재 칸의 이동 가능 칸 수
        int jmp = board[x][y];
        // 이동 가능 칸 수가 0이라면 못 움직임 
        // -> 다음 탐색으로
        if (jmp == 0) continue;

        // 끝 점에 도착 가능하다면 종료
        if (x == n - 1 && y == n - 1)
        {
            cout << "HaruHaru";
            return 0;
        }

        // 방문한 적이 없고, board 를 벗어나지 않는 좌표라면
        // 아래 칸 혹은 오른쪽 칸으로 이동
        if (x + jmp < n && !visited[x + jmp][y])
        {
            visited[x + jmp][y] = true;
            st.emplace(x + jmp, y);
        }
        if (y + jmp < n && !visited[x][y + jmp])
        {
            visited[x][y + jmp] = true;
            st.emplace(x, y + jmp);
        }
    }

    cout << "Hing";


    return 0;
}
