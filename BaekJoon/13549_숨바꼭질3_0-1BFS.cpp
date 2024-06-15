#include <iostream>
#include <vector>
#include <limits>
#include <deque>

using namespace std;

// 숨바꼭질3 13549 0-1BFS
// 가중치가 낮은 간선부터 탐색 -> push_front


// 0-1BFS로 n -> k 최소 시간 계산
int zero_oneBFS(int n, int k)
{
    // n이 k보다 크거나 같으면, 뒤로 가야하기에 n - k 리턴
    if (n >= k) return n - k;
    
    // 최대 범위
    const int maxRange{ max(n * 2, k * 2) };
    // 최소 시간 벡터
    vector<int> dist(maxRange + 1, numeric_limits<int>::max());
    deque<int> dq;
    
    // init
    dq.push_back(n);
    dist[n] = 0;
    
    while (!dq.empty())
    {
        // 현재 위치
        int cur = dq.front();
        dq.pop_front();

        if (cur == k) return dist[cur];

        // 순간이동, 0초
        if (cur * 2 <= maxRange && dist[cur * 2] > dist[cur])
        {
            dist[cur * 2] = dist[cur];
            // 가중치가 낮음 -> 우선순위가 높다
            // 따라서, push_front
            dq.push_front(cur * 2);
        }
        // 앞으로 한 칸, 1초
        if (cur + 1 <= maxRange && dist[cur + 1] > dist[cur] + 1)
        {
            dist[cur + 1] = dist[cur] + 1;
            dq.push_back(cur + 1);
        }
        // 뒤로 한 칸, 1초
        if (cur - 1 >= 0 && dist[cur - 1] > dist[cur] + 1)
        {
            dist[cur - 1] = dist[cur] + 1;
            dq.push_back(cur - 1);
        }
    }

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    cout << zero_oneBFS(n, k);

    return 0;
}
