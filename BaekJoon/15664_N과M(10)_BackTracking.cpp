#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N과M(10) 15664 BackTracking
// O( M * N^M )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int& e : v)
    {
        cin >> e;
    }

    // 사전순 처리와 중복 방지를 위한 오름차순 정렬
    sort(v.begin(), v.end());

    vector<int> seq;

    auto DFS = [&](auto&& self, int start) -> void {
        // m 개를 선택했다면 출력
        if (seq.size() == m)
        {
            for (const int& e : seq)
            {
                cout << e << " ";
            }
            cout << "\n";
            return;
        }

        for (int i = start; i < n; ++i)
        {
            // 동일 깊이에서 중복 값 건너뜀
            if (i > start && v[i] == v[i - 1]) continue;

            seq.push_back(v[i]);
            self(self, i + 1);
            seq.pop_back(); // 백트래킹
        }
        };

    DFS(DFS, 0);


    return 0;
}
