#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 백준 1260 DFS/BFS
// DFS/BFS 구현 연습 문제


class Graph {
private:
    int numVertex;                  // 정점의 수
    vector<vector<int>> adjList;    // 인접 정점 리스트
    vector<bool> visited;           // 방문 여부

    void dfsUtil(int v)
    {
        visited[v] = true;
        cout << v << " ";
        for (const int i : adjList[v])
        {
            if (!visited[i]) dfsUtil(i);
        }
    }
public:
    Graph(int n) : numVertex(n), adjList(n + 1), visited(n + 1, false) {}

    // 인접 리스트 오름차순 정렬
    void sortAdjList()
    {
        for (auto& row : adjList)
        {
            ranges::sort(row);
        }
    }

    // DFS
    void DFS(int start)
    {
        dfsUtil(start);
        cout << "\n";
    }

    // BFS
    void BFS(int start)
    {
        // 방문 테이블 초기화
        fill(visited.begin(), visited.end(), false);

        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int current = q.front();
            cout << current << " ";
            q.pop();

            for (const auto& neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << "\n";
    }

    // 연산자 오버로딩
    void operator()(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, v;
    cin >> n >> m >> v;

    Graph g(n);

    for (int i = 0; i < m; ++i)
    {
        int v, w;
        cin >> v >> w;
        g(v, w);
    }

    g.sortAdjList();
    g.DFS(v);
    g.BFS(v);

    
    return 0;
}
