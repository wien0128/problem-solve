#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
using Graph = vector<vector<pair<int, int>>>;
using Pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;

constexpr double INF{ 1e9 }; // 무한대

// 백준 1753 Dijkstra
// 처음 푸는 다익스트라, 조금 어렵다.
// 그리디 + DP의 형태 
// 음의 가중치가 있다면 사용 불가

// vector에서 push_back 대신 emplace, emplace_back 사용
// => 복사&이동 비용 절감, 성능 쬐끔 좋아짐
// => make_pair 쓸 필요 없음, 생성자 알아서 호출 후 객체를 바로 삽입


void dijkstra(int start, Graph& graph, vector<int>& dist)
{
    Pq pq; // 최소 힙
    pq.emplace(0, start); // 시작 정점 삽입
    dist[start] = 0; // 자기 자신의 거리는 항상 0

    while (!pq.empty())
    {
        // pq에서 가장 짧은 거리의 정점 꺼냄
        auto [currentDist, current] { pq.top() };
        pq.pop();

        // 현재 정점까지의 최단 거리가 이미 더 짧으면 무시
        if (dist[current] < currentDist) continue;

        // 그래프 순회
        for (const auto& [next, weight] : graph[current])
        {
            // 현재 정점을 거쳐 인접 정점으로 가는 거리
            int newDist = currentDist + weight;

            // 새로운 거리가 기존 최단 거리보다 짧다면,
            if (newDist < dist[next])
            {
                dist[next] = newDist; // 최단 거리 갱신
                pq.emplace(newDist, next); // 새로운 [거리, 정점] 추가
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // V - 노드(Node)의 개수
    // E - 간선(Edge)의 개수
    // K - 시작 정점
    int v, e;
    cin >> v >> e;

    int start;
    cin >> start;

    Graph graph(v + 1); // 인접 리스트 그래프
    vector<int> dist(v + 1, INF); // 정점별 최단 거리

    for (int i = 0; i < e; ++i)
    {
        int u, v, w; // 노드 u -> v 경로와 가중치 w
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    dijkstra(start, graph, dist);

    for (int i = 1; i <= v; ++i)
    {
        if (dist[i] == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << dist[i] << "\n";
        }
    }
    
    return 0;
}
