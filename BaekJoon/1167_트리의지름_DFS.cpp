#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

// 트리의_지름 1167 DFS
// 트리는 사이클이 없는 그래프임
// 따라서 임의의 두 노드 간의 경로는 유일
// 첫 번째 DFS: 임의의 정점 x에서 가장 먼 정점 y를 찾음
// 두 번째 DFS: 정점 y에서 가장 먼 정점 z를 찾음
// 트리의 지름 = 정점 y와 z를 연결하는 경로


// 인접 리스트 트리 + DFS
class Tree {
private:
    int n; // 정점의 개수
    vector<vector<pii>> adjList; // (정점, 가중치) 인접 리스트

    // DFS
    pii DFS(int u, int parent)
    {
        pii farthest = { u, 0 }; // { 가장 먼 노드, 거리 }

        // u의 모든 인접 노드 탐색
        for (auto& [v, w] : adjList[u])
        {
            if (v == parent) continue; // 이전에 방문한 노드는 무시

            auto candidate = DFS(v, u); // v에서 가장 먼 노드와 거리 찾기
            candidate.second += w; // 자식 노드까지의 거리에 현재 간선 가중치 더하기
            
            // 더 먼 노드 발견 시 갱신
            if (candidate.second > farthest.second)
            {
                farthest = candidate;
            }
        }

        // 현재 노드 u에서 가장 먼 노드와 거리 반환
        return farthest;
    }
public:
    Tree(int n) : n(n), adjList(n + 1) {}

    // 간선 추가
    void addEdge(int u, int v, int w)
    {
        adjList[u].emplace_back(v, w); // u -> v
    }

    // 트리 지름 구하기
    int getDiamater()
    {
        // 1번 노드에서 시작하여 가장 먼 노드 찾기
        auto farthestNode = DFS(1, -1);
        // 첫 번째 DFS에서 찾은 노드에서 가장 먼 노드 찾기
        auto diamater = DFS(farthestNode.first, -1);
        return diamater.second; // 트리의 지름 반환
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v;
    cin >> v;

    Tree tree(v);

    for (int i = 0; i < v; ++i)
    {
        int u;
        cin >> u;
        while (true)
        {
            int v, w;
            cin >> v;
            if (v == -1) break; // 입력 끝 구분
            cin >> w;
            tree.addEdge(u, v, w);
        }
    }

    cout << tree.getDiamater();

    return 0;
}
