#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N과M(9) 15663 BackTracking
// 중복 방지가 핵심인 문제
// O( M * N^M )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int& a : v)
    {
        cin >> a;
    }

    // 사전순 처리를 위한 오름차순 정렬
    sort(v.begin(), v.end());

    vector<bool> isUsed(n, false);  // 중복 방지
    vector<int> seq;
    seq.reserve(m);

    auto DFS = [&](auto&& self, int depth) -> void {
        // m 개의 수를 모두 선택했다면 출력
        if (depth == m)
        {
            for (const auto& a : seq)
            {
                cout << a << ' ';
            }
            cout << '\n';
            return;
        }

        // 같은 깊이에서 동일 수 선택 방지
        int prev{ -1 };
        for (int i = 0; i < n; ++i)
        {
            // 이미 수열에 있는 수이거나, 이전에 선택한 수면 건너뜀
            if (isUsed[i] || v[i] == prev)
            {
                continue;
            }

            isUsed[i] = true;
            seq.push_back(v[i]);
            self(self, depth + 1);
            seq.pop_back();
            isUsed[i] = false;
            prev = v[i];
        }
    };

    DFS(DFS, 0);


    return 0;
}
