#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 문제집 1766 TopologicalSort, PriorityQueue
// Kahn's Algorithm 이용
// 연결 리스트를 활용하면 TimeComplexity 더 낮출 수도?
// O( (N + M)logN ) = O( (V + E)logV )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 진입 차수가 없다(0) = 선행 문제 X

    int n, m;
    cin >> n >> m;

    // 쉬운(번호가 작은) 문제 최소 힙
    // 진입 차수가 0인 문제들만 push
    priority_queue<int, vector<int>, greater<>> pq;
    // 문제 별 진입 차수 벡터
    vector<int> inDegree(n + 1);
    // 문제 간의 관계 그래프 2D벡터
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y); // x -> y
        ++inDegree[y];         // 문제 y 진입 차수 증가
    }

    // 진입 차수가 0인 모든 문제 pq.push
    for (int i = 1; i <= n; ++i)
    {
        if (inDegree[i] == 0)
        {
            pq.push(i);
        }
    }

    // 위상 정렬
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        cout << cur << " "; // 현재 푼 문제 출력

        // 현재 문제 해결 후, 연결된 문제들 진입 차수 감소
        for (int next : graph[cur])
        {
            if (--inDegree[next] == 0)
            {
                pq.push(next);
            }
        }
    }


    return 0;
}
