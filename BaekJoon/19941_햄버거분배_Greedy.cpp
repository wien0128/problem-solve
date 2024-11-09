#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 햄버거분배 19941 Greedy
// O( n * k )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string table;
    cin >> table;

    int res{ 0 };   // 최대로 먹을 수 있는 사람 수
    for (int i = 0; i < n; ++i)
    {
        // 현재 자리가 사람이라면
        if (table[i] == 'P')
        {
            // -k ~ i ~ +k 범위 내 햄버거 탐색
            for (int j = max(0, i - k); j <= min(n - 1, i + k); ++j)
            {
                // 현재 탐색 자리가 햄버거라면
                if (table[j] == 'H')
                {
                    // 햄버거 먹은 표시 후 사람 수 증가
                    table[j] = '-';
                    ++res;
                    // 한 사람당 한 햄버거만 먹음
                    break;
                }
            }
        }
    }

    cout << res;


    return 0;
}
