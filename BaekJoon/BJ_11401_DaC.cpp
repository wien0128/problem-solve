#include <iostream>

using namespace std;
constexpr int MOD{ 1000000007 };
using ll = long long;

// 백준 11401 Divide_and_Conquer
// nCk % p = (n! / (k! * (n - k)!)) % p

// 팩토리얼
ll facto(ll begin, ll end)
{
    ll tmp{ 1 };
    for (int i = begin; i <= end; ++i)
    {
        tmp = (tmp * i) % MOD;
    }

    return tmp;
}

// n^k % P, Divide-and_Conquer
ll power(ll n, ll k)
{
    if (k == 0) return 1;   // n^0 = 1
    if (k == 1) return n % MOD;     // n^1 = n

    ll half = power(n, k >> 1) % MOD;   // n^(k / 2)
    half = (half * half) % MOD;     // n^(k / 2) * n^(k / 2)

    //                           n^(k / 2) * n^(k / 2) * n
    return (k % 2 == 0) ? half : (n * half) % MOD;
}

// 모듈러 역원(페르마 소정리)
// a^p = a % p
// a^p-1 = 1 % p
// a^p-2 = a^-1 % p
ll modInverse(ll n, ll k)
{
    if (k == 1) return n;
    if (k == 0 || n == k) return 1;
    if (n - k == 1) return n;

    ll a{ facto(n - k + 1, n) };    // n*(n - 1)*...*(n - k + 1)
    ll b{ facto(2, k) };            // k!        

    // nCk % P = ((A % P) * B^P-2 % P) % P
    return ((a % MOD) * power(b, MOD - 2) % MOD) % MOD;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    n %= MOD;
    k %= MOD;

    cout << modInverse(n, k);


    return 0;
}
