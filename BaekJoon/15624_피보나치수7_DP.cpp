#include <iostream>

using namespace std;

constexpr int MOD = 1000000007;

// 피보나치수7 15624 DP
// 매 반복마다 MOD하는 게 핵심
// O( N )


int fibonacci(int n)
{
    if (n < 2) return n;

    int x{ 0 }, y{ 1 };
    for (int i = 2; i <= n; ++i)
    {
        y = (x + y) % MOD;      // f(n) 계산
        x = y - x;              // f(n - 1) 계산
        if (x < 0) x += MOD;    // 음수라면 양수로 보정
    }

    return y;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    cout << fibonacci(n);


    return 0;
}
