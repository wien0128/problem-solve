#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 백준 24444 BFS
// 기초적인 BFS 구현 문제

class Graph {
private:
    vector<vector<int>> adj_list;  // 간선 리스트
    queue<int> q;                  // 인접 정점 큐
    vector<bool> visited;          // 방문 여부
    vector<int> visit_order;       // 정점 방문 순서
    int current_order;             // 현재 방문 순서
public:
    // 생성자, 1-based-indexing
    Graph(int n) : adj_list(n + 1), visited(n + 1, false), visit_order(n + 1, 0), current_order(1){}

    // 간선 추가
    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    // 인접 리스트 오름차순 정렬
    void prepare() {
        for (auto& neighbors : adj_list)
        {
            ranges::sort(neighbors, greater<>());
        }
    }

    // BFS
    void bfs(int node) {
        
        visited[node] = true;
        visit_order[node] = current_order++;   // 시작 노드는 항상 첫 번째 방문
        q.push(node);
        
        while (!q.empty())
        {
            int current = q.front(); // 현재 정점
            q.pop();

            // 현재 정점의 모든 인접 정점 순회
            for (auto& neighbors : adj_list[current])
            {
                // 이전에 방문했는가?
                if (!visited[neighbors])
                {
                    q.push(neighbors); // 인접 정점 push
                    visited[neighbors] = true; // 방문 표시
                    visit_order[neighbors] = current_order++; // 방문 순서 기록
                }
            }
        }
    }

    // 출력
    void print_visit_order() const
    {
        for (size_t i = 1; i < visit_order.size(); ++i)
        {
            cout << visit_order[i] << "\n";
        }
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    Graph graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u, v);
    }

    graph.prepare();

    graph.bfs(r);
    graph.print_visit_order();
    
    return 0;
}
