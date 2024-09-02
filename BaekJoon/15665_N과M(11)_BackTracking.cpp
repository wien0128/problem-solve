#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N과M(11) 15665 BackTracking
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

    // 사전순 처리와 중복 제거를 위한 오름차순 정렬
    sort(v.begin(), v.end());
    // 중복 원소들 제거
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<int> seq(m);

    auto DFS = [&](auto&& self, int depth) -> void {
        // m 개를 선택했다면 출력
        if (depth == m)
        {
            for (const int& e : seq)
            {
                cout << e << " ";
            }
            cout << "\n";
            return;
        }

        for (int i = 0; i < v.size(); ++i)
        {
            seq[depth] = v[i];
            self(self, depth + 1);
        }
        };

    DFS(DFS, 0);


    return 0;
}
