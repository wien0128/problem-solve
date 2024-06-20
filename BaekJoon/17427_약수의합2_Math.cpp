#include <iostream>

using namespace std;
using ll = long long;

// 약수의_합2 17427 Math
// 약수 분포에 대한 규칙을 찾아야 하는 문제
// 깡으로 풀면 시간 초과난다.


ll sumOfDivisors(int n)
{
    ll sum{ 0 };

    // i가 약수로 등장하는 횟수 = N / i
    for (int i = 1; i <= n; ++i)
    {
        sum += i * (n / i);
    }

    return sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << sumOfDivisors(n);
    

    return 0;
}
