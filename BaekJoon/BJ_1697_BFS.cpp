#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 백준 1697 BFS
// 최단 경로 찾기 문제
// 아이디어 떠올리기가 어려웠다

constexpr int MAX = 100000;

int BFS(int n, int k)
{
    if (n >= k) return n - k; // 출발점이 종착점보다 크거나 같을 경우 뒤로 이동

    vector<int> visited(MAX + 1, 0);    // 방문 여부 + 횟수 벡터
    queue<int> q;

    q.push(n);
    visited[n] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // for-ranged : std::initializer_list<int>
        for (int next : {cur - 1, cur + 1, cur * 2})
        {
            // k에 도달했을 경우 이동 횟수 반환
            if (next == k)
            {
                return visited[cur];
            }
            // 유효 범위 && 방문 여부 확인
            if (next >= 0 && next <= MAX && !visited[next])
            {
                q.push(next);
                visited[next] = visited[cur] + 1;   // 이동 횟수 기록
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    cout << BFS(n, k);

    return 0;
}
