#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
using pii = pair<int, int>;

// 최스_스패닝_트리 1197 MST
// 프림 알고리즘 풀이
// 코드는 간단한데 어렵다.


// 프림 알고리즘
class Prim {
private:
    int v;  // 정점의 수
    vector<vector<pii>> adjList; // (가중치, 정점) 인접 리스트 
public:
    Prim(int v) : v(v) { adjList.resize(v); }

    // 간선 추가
    void addEdge(int u, int v, int weight)
    {
        adjList[u].emplace_back(weight, v);
        adjList[v].emplace_back(weight, u);
    }

    // MST 총 가중치 계산
    int getMST()
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;  // (가중치, 정점) 최소 힙
        vector<int> key(v, numeric_limits<int>::max());     // 각 정점의 도달하는 최소 가중치, 무한대로 초기화
        vector<bool> visited(v, false);                     // 정점 방문 여부
        int res{ 0 };   // MST의 총 가중치

        key[0] = 0;         // 시작 정점은 가중치 0
        pq.push({ 0,0 });   // (가중치, 정점)

        while (!pq.empty())
        {
            int u{ pq.top().second };   // 현재 정점
            pq.pop();

            // 이미 방문한 정점은 무시
            if (visited[u]) continue;

            visited[u] = true;  // 현재 정점 방문 표시
            res += key[u];      // 현재 정점까지의 가중치 + 총 가중치

            // 모든 인접 정점 탐색
            for (const auto& [weight, v] : adjList[u])
            {
                // 방문하지 않았고, 새로운 가중치가 기존 가중치보다 작은 경우
                if (!visited[v] && weight < key[v])
                {
                    key[v] = weight;
                    pq.push({ key[v], v });
                }
            }
        }
        return res;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    cin >> v >> e;

    Prim p(v);

    for (int i = 0; i < e; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        p.addEdge(--u, --v, w); // 0-based indexing
    }

    cout << p.getMST();


    return 0;
}
