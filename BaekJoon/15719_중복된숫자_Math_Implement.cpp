#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// 중복된숫자 15719 Math, Implement
// m = 실제합 - 기대합, m을 제외한 원소들은 중복이 불가하기에 가능
// XOR 성질을 이용하여도 풀이 가능
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 실제 XOR 값, 기대 XOR 값
    ll xorArr{ 0 }, xorExpected{ 0 };
    ll n;
    cin >> n;

    // 1 ~ n-1까지 XOR 한 기대 XOR 값
    for (int i = 1; i <= n - 1; ++i) xorExpected ^= i;
    // 실제 원소들을 XOR 한 실제 XOR 값
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        xorArr ^= x;
    }

    // 중복되지 않은 숫자는 XOR의 성질에 의해 상쇄
    // 1 ~ n까지의 XOR 연산은 n % 4와 동일한 패턴
    cout << (xorArr ^ xorExpected);

    // 실제합
    ll n, sum{ 0 };
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        sum += x;
    }

    // 중복된 숫자 = 실제합 - 기대합
    cout << sum - (n * (n - 1) / 2);


    return 0;
}
