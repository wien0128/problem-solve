#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 24479 DFS
// 기초적인 DFS 구현 문제

class Graph {
private:
    vector<vector<int>> adj_list;   // 간선 리스트
    vector<bool> visited;           // 정점 방문 여부
    vector<int> visit_order;        // 정점 방문 순서
    int current_order;             // 현재 방문 순서
public:
    // 생성자, 1-based-indexing
    Graph(int n) : adj_list(n + 1), visited(n + 1, false), visit_order(n + 1, 0), current_order(1) {}

    // 간선 추가
    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    // 인접 리스트 오름차순 정렬
    void prepare() {
        for (auto& neighbors : adj_list)
        {
            sort(neighbors.begin(), neighbors.end());
        }
    }

    // DFS
    void dfs(int node) {
        visited[node] = true;   // 현재 정점 방문 표시
        visit_order[node] = current_order++;   // 방문 순서 기록

        for (const auto& neighboor : adj_list[node])
        {
            // 이웃 정점이 아직 방문되지 않았다면
            if (!visited[neighboor])
            {
                dfs(neighboor); // DFS 수행
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

    graph.dfs(r);
    graph.print_visit_order();
    
    return 0;
}
