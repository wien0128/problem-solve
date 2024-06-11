#include <iostream>

using namespace std;

// 상근이의_여행 9372 최소 신장 트리(MST)
// 트리에서 정점과 변에 대한 정리 { V = E - 1 }
// 경로를 구하는 게 아닌 단순 횟수만 구하면 된다.


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
        }

        cout << (n - 1) << "\n";
    }


    return 0;
}
