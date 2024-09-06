#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 눈덩이굴리기 21735 BackTracking
// O( 2^m )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1); // 1-based indexing
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }

    int res{ 0 };   // 최종 눈덩이 크기

    auto DFS = [&](auto&& self, int snowBall, int time, int pos) -> void {
        // 시간이 끝났거나, 범위를 벗어났다면
        if (time == m || pos > n)
        {
            res = max(res, snowBall);
            return;
        }

        res = max(res, snowBall);

        // 1칸 전진
        if (pos + 1 <= n)
        {
            self(self, snowBall + v[pos + 1], time + 1, pos + 1);
        }
        // 2칸 던지기
        if (pos + 2 <= n) 
        {
            self(self, (snowBall / 2) + v[pos + 2], time + 1, pos + 2);
        }
        };

    DFS(DFS, 1, 0, 0);

    cout << res;
    

    return 0;
}
