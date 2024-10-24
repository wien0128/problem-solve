#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 기타줄 1049 Greedy
// O( M )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    int minPackage{ 1001 }, minSingle{ 1001 };
    cin >> n >> m;

    while (m--)
    {
        int p, s;
        cin >> p >> s;
        minPackage = min(minPackage, p);
        minSingle = min(minSingle, s);
    }

    int res = min({
        // 패키지 + 낱개 가격
        (n / 6) * minPackage + (n % 6) * minSingle,
        // 패키지 가격 (올림)
        ((n + 5) / 6) * minPackage,
        // 낱개 가격
        n * minSingle 
        });

    cout << res;


    return 0;
}
