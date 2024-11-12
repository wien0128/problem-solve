#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 돌게임3 9657 DP
// DP[i] = !(DP[i - 1] && DP[i - 3] && DP[i - 4])
// 점화식을 이용해도 되지만 직접 계산해보면 패턴이 존재
// O( 1 )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if (n % 7 == 2 || n % 7 == 0)
    {
        cout << "CY";
    }
    else
    {
        cout << "SK";
    }


    return 0;
}
