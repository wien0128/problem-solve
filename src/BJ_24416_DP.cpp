#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 24416 DP


int fib_call{ 0 }, fibonacci_call{ 0 };

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        fib_call++;
        return 1;
    }
    else
    {
        return (fib(n - 1) + fib(n - 2));
    }
}

int fibonacci(int n)
{
    vector<int> dp(n + 1);
    dp[1] = dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        fibonacci_call++;
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    fib(n);
    fibonacci(n);

    cout << fib_call << " " << fibonacci_call << '\n';


    return 0;
}
