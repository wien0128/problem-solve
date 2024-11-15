#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
constexpr int MOD = 1'000'000'000;  // 10^9

// 피보나치수의확장 1788 DP
// 양수, F(n) = F(n - 1) + F(n - 2) (n >= 2)
// 음수, F(-n) = (-1)^n+1 * F(n) (n < 0)
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "0\n0";
        return 0;
    }

    // 부호 변수, n이 0보다 작고 2의 배수라면 -1, 아니면 +1
    int sign{ (n < 0 && (-n) % 2 == 0) ? -1 : 1 };
    // 절댓값으로 변환 후 양수 피보나치 계산
    n = abs(n);

    // F(0) = 0, F(1) = 1
    int a{ 0 }, b{ 1 };
    for (int i = 2; i <= n; ++i)
    {
        int tmp = (a + b) % MOD;
        a = b;
        b = tmp;
    }

    cout << sign << "\n" << b;


    return 0;
}
