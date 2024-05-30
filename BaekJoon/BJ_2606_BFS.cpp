#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 백준 2606 BFS
// DFS/BFS 연습 문제


class Graph {
private:
    vector<bool> visited;           // 방문 여부
    vector<vector<int>> adj_list;   // 인접 정점 리스트
public:
    Graph(int n) : adj_list(n + 1), visited(n + 1, false) {}

    int bfs(int start) {
        queue<int> q;
        int infectedCnt{ 0 };

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            ++infectedCnt;

            for (const auto& neighbor : adj_list[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return infectedCnt - 1; // 시작 컴퓨터 제외
    }

    // 연산자 오버로딩
    void operator()(int u, int v) {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph(u, v);
    }

    cout << graph.bfs(1);

    
    return 0;
}
