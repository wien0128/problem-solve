#include <iostream>

using namespace std;

typedef long long ll;

// 백준 1629 Divide-and-Conquer
// 지수 법칙이나 모듈러의 성질을 알면 쉬운 문제
// a^(n + m) = a^n * a^m
// (a * b) % c = ((a % c) * (b % c)) % c


// (a^b) % c
ll expoAndMod(ll a, ll b, ll c)
{
    if (b == 0) return 1; // a^0 = 1
    if (b == 1) return a % c; // a^1 = a

    ll half{ expoAndMod(a, b / 2, c) }; // = a^(b / 2)
    if (b % 2 == 0)
    {
        // b가 짝수라면
        // a^b = a^(b / 2) * a^(b / 2)
        return (half * half) % c;
    }
    else
    {
        // b가 홀수라면
        // a^b = a^(b / 2) * a^(b / 2) * a
        return (((half * half) % c) * a) % c;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c;
    cin >> a >> b >> c;

    cout << expoAndMod(a, b, c);


    return 0;
}
