#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tuple>

using namespace std;

// 최스_스패닝_트리 1197 MST
// 유니온 파인드 + 크루스칼
// 처음 푸는 유형의 문제라 어려웠다


// 유니온 파인드 자료구조
// parent[v] -> n, v의 부모가 n이라는 의미
class UnionFind {
private:
    vector<int> parent; // 부모 노드 벡터
    vector<int> rank;   // 트리 랭크 벡터
public:
    // 각 노드의 부모를 자기자신으로 설정, 랭크는 0
    UnionFind(int n) : parent(n), rank(n, 0) 
    {
        // parent = { 0, 1, 2, ... , n - 1 }
        iota(parent.begin(), parent.end(), 0);
    }

    // 경로 압축으로 부모 노드 찾기
    int find(int u) 
    {
        // 부모 노드가 자기 자신이면 루트 노드
        if (parent[u] == u) return u;
        // 다르다면 만나는 모든 부모를 루트 노드로 설정
        return parent[u] = find(parent[u]); // 경로 압축
    }

    // Union-by-Rank, 랭크(높이) 기준 합치기
    void unite(int u, int v)
    {
        u = find(u);
        v = find(v);
        // 서로 다른 트리라면
        if (u != v)
        {
            // 랭크 낮은 트리를 랭크 높은 트리에 합침
            if (rank[u] > rank[v])
            {
                parent[v] = u; // v의 부모를 u로
            }
            else
            {
                parent[u] = v; // u의 부모를 v로

                // 랭크가 같으면 v의 랭크 증가
                if (rank[u] == rank[v]) 
                    ++rank[v];
            }
        }
    }
};

// 크루스칼 알고리즘
class Kruskal {
private:
    int v, e;   // 정점 수, 간선 수
    vector<tuple<int, int, int>> edges; // 간선 정보 벡터 (정점1, 정점2, 가중치)
public:
    Kruskal(int v, int e) : v(v), e(e)
    {
        edges.reserve(e);   // capacity 미리 할당
    }

    // 간선 추가
    void addEdge(int u, int v, int w)
    {
        edges.emplace_back(w, u, v);
    }

    // MST 가중치 계산
    int getMST()
    {
        sort(edges.begin(), edges.end()); // 가중치 기준 오름차순 정렬

        UnionFind ds(v);
        int mstWeight{ 0 }; // MST의 총 가중치

        // 모든 간선 순회
        for (const auto& [w, u, v] : edges)
        {
            // 같은 부모를 가진다 == 사이클 형성
            if (ds.find(u) != ds.find(v))
            {
                ds.unite(u, v);
                mstWeight += w;
            }
        }

        return mstWeight;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    cin >> v >> e;

    Kruskal k(v, e);

    for (int i = 0; i < e; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        k.addEdge(u - 1, v - 1, w); // 0-based indexing
    }

    cout << k.getMST();


    return 0;
}
