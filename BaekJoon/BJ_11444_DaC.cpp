#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using matrix = vector<vector<long long>>;   // 행렬
constexpr ll MOD{ 1000000007 };

// BJ 11444 Dvide-and-Conquer
// 피보나치 점화식을 행렬 꼴로 변환 후 곱으로 풀이
// 분할 정복으로 구현하는 문제
// { Fn+2 Fn } = { 1 1 } ^ n
// { Fn Fn-1 }   { 1 0 }


// 행렬 곱
matrix multiplyMatrix(const matrix& a, const matrix& b)
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

// 행렬 거듭제곱
matrix matrixPower(const matrix& base, ll n)
{
    if (n == 0) return { {1, 0}, {0, 1} };
    if (n == 1) return base;
    if (n % 2 == 1)
    {
        matrix half = matrixPower(base, n / 2);
        return multiplyMatrix(base, multiplyMatrix(half, half));
    }
    
    matrix half = matrixPower(base, n / 2);
    return multiplyMatrix(half, half);
}

// 피보나치
ll fibonacci(ll n)
{
    if (n == 0) return 0;
    
    matrix base = { {1, 1}, {1, 0} };
    matrix res = matrixPower(base, n - 1);

    return res[0][0];
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
