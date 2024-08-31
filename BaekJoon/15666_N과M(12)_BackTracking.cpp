#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N과M(12) 15666 BackTracking
// O( N^M )


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

    vector<int> seq;
    seq.reserve(m);

    auto DFS = [&](auto&& self, int start) -> void {
        // m 개의 수를 모두 선택했다면 출력
        if (seq.size() == m)
        {
            for (const int& a : seq)
            {
                cout << a << ' ';
            }
            cout << '\n';
            return;
        }
        
        int prev{ -1 }; // 같은 깊이 동일 수 선택 방지
        for (int i = start; i < n; ++i)
        {
            // 이전에 선택한 수와 동일하다면 건너뜀
            if (v[i] == prev) continue;
            
            seq.push_back(v[i]);
            self(self, i);
            seq.pop_back(); // 백트래킹
            prev = v[i];
        }
    };

    DFS(DFS, 0);


    return 0;
}
