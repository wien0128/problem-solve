#include <iostream>
#include <vector>

using namespace std;

// 백준 9461 DP
// 또보나치지만 메모리가 빡빡한
// dp[n] = dp[n - 2] + dp[n - 3]

long long padovan(int n)
{
    if (n <= 3) return 1;

    long long a{ 1 }, b{ 1 }, c{ 1 };
    long long next{ 2 };

    for (int i = 4; i <= n; i++)
    {
        next = a + b;
        a = b;
        b = c;
        c = next;
    }

    return next;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin >> T;

    int n;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        cout << padovan(n) << '\n';
    }


    return 0;
}
