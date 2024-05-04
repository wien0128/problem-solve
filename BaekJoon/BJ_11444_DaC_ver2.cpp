#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using matrix = vector<vector<long long>>;   // 행렬
constexpr ll MOD{ 1000000007 };

// BJ 11444 Dvide-and-Conquer ver.2
// 피보나치 점화식을 행렬 꼴로 변환 후 곱으로 풀이를
// 분할 정복으로 구현하는 문제
// { Fn+1 Fn   } = { 1 1 } ^ n
// { Fn   Fn-1 }   { 1 0 }

// 곱하기 오퍼레이터 행렬 곱으로 오버로딩
matrix operator*(const matrix& a, const matrix& b)
{
    matrix tmp(2, vector<ll>(2, 0));
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                tmp[i][j] += a[i][k] * b[k][j];
            }
            tmp[i][j] %= MOD;
        }
    }
    return tmp;
}

// 피보나치
ll fibonacci(ll n)
{
    matrix res = { {1, 0}, {0, 1} };    // 단위 행렬
    matrix base = { {1, 1}, {1, 0} };   // 피보나치 수열 점화식

    // Divide-and-Conquer
    while (n > 0)
    {
        // n이 홀수인가?
        if (n % 2 == 1)
        {
            res = res * base;
        }
        base = base * base;
        n /= 2;
    }

    return res[0][1];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    cout << fibonacci(n);


    return 0;
}
