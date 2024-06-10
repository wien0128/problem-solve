#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 백준 1707 BFS/DFS
// 이분 그래프는 알았지만 구현이 빡신 문제
// 


class Graph {
private:
    vector<vector<int>> adj;    // 인접 리스트 
    vector<int> group;          // 각 정점의 그룹값
    // 초기 = 0
    // 그룹 = 1 or -1  

    void BFS(int start, bool& isBipartite)
    {
        queue<int> q;
        q.push(start);
        group[start] = 1;

        while (!q.empty() && isBipartite)
        {
            int node = q.front();
            q.pop();

            // 현재 정점의 모든 인접 정점 탐색
            for (int neighbor : adj[node])
            {
                // 인접 정점이 어떤 그룹에도 속하지 않은 경우
                if (group[neighbor] == 0)
                {
                    // 인접 정점을 현재 정점과 다른 그룹으로 배정
                    // 1 or -1
                    group[neighbor] = -group[node];
                    q.push(neighbor);
                }
                // 인접 정점이 현재 정점과 같은 그룹일 경우
                else if (group[neighbor] == group[node])
                {
                    // 이분 그래프가 아니므로 = false
                    isBipartite = false;
                    return;
                }
            }
        }
    }

    void DFS(int node, bool& isBipartite)
    {
        for (int neighbor : adj[node])
        {
            if (group[neighbor] == 0)
            {
                group[neighbor] = -group[node];
                DFS(neighbor, isBipartite);
            }
            else if (group[neighbor] == group[node])
            {
                isBipartite = false;
                return;
            }
        }
    }
public:
    Graph(int v) : adj(v + 1), group(v + 1, 0) {}   // 1-based indexing

    // 간선 추가
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 이분 그래프 판독 메서드
    bool isBipartite()
    {
        bool isBipartite{ true };
        for (int i = 1; i < adj.size() && isBipartite; ++i)
        {
            // 정점 i가 어떤 그룹에도 속하지 않은 경우
            if (group[i] == 0)
            {
                BFS(i, isBipartite);
            }
        }
        return isBipartite;
    }
    
    // DFS용 이분 그래프 판독 메서드
    bool isBipartiteDFS()
    {
        bool isBipartite{ true };
        for (int i = 1; i < adj.size() && isBipartite; ++i)
        {
            if (group[i] == 0)
            {
                group[i] = 1;
                DFS(i, isBipartite);
            }
        }
        return isBipartite;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k;

    while (k--)
    {
        int v, e;
        cin >> v >> e;

        Graph graph(v);

        for (int i = 0; i < e; ++i)
        {
            int u, v;
            cin >> u >> v;
            graph.addEdge(u, v);
        }

        if (graph.isBipartite())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }


    return 0;
}
