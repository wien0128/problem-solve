#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using AdjList = vector<vector<int>>;

// 백준 11725 Tree
// DFS/BFS 공부하기 좋은 문제


void DFS(int node, int parent, const AdjList& adjList, vector<int>& res)
{
    res[node] = parent; // 현재 노드 부모를 저장
    // 현재 노드의 모든 인접 노드 탐색
    for (int neighbor : adjList[node])
    {
        if (neighbor != parent) // 부모 노드 중복 탐색 방지
        {
            DFS(neighbor, node, adjList, res);
        }
    }
}

void BFS(int n, const AdjList& adjList, vector<int>& res)
{
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(1);
    visited[1] = true;
    res[1] = 0; // 1번 노드는 루트 노드, 부모 없음

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // 현재 노드의 모든 인접 노드 탐색
        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                res[neighbor] = node; // 자식 노드의 부모를 현재 노드로 설정
                q.push(neighbor);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 인접 리스트
    AdjList adjList(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].emplace_back(v);
        adjList[v].emplace_back(u);
    }

    // 각 노드의 부모 노드 벡터
    vector<int> res(n + 1);

    DFS(1, 0, adjList, res);

    //BFS(n, adjList, res);
    
    // 루트 노드 제외 출력
    for (int i = 2; i <= n; ++i)
    {
        cout << res[i] << "\n";
    }

    return 0;
}
