#include <iostream>

using namespace std;

// BABBA 9625 DP
// A[k] = B[k - 1]
// B[k] = A[k - 1] + B[k - 1]
// 간단한 피보나치 문제
// O( K )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k;

    int a{ 1 }, b{ 0 };

    for (int i = 0; i < k; ++i)
    {
        int nextA = b;
        int nextB = a + b;
        a = nextA;
        b = nextB;
    }

    cout << a << " " << b;

    return 0;
}
