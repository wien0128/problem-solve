#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using matrix = vector<vector<int>>; // 행렬
constexpr int MOD{ 1000 };

// 백준 10830 Divide-and-Conquer


// 행렬 곱
matrix multiply(const matrix& A, const matrix& B, const int n)
{
    // MOD 연산은 큰 비용을 요구함.
    // 따라서 대입 직전에만 MOD 연산.
    matrix res(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ll tmp{ 0 };
            for (int k = 0; k < n; ++k)
            {
                tmp += A[i][k] * B[k][j];
            }
            res[i][j] = tmp % MOD;
        }
    }
    return res;
}

// 행렬 제곱
matrix power(const matrix& A, ll b, const int n)
{
    if (b == 1) return A;

    // 지수가 짝수인가?
    if (b % 2 == 0)
    {
        // 그렇다.
        // A^(b / 2) * A(b / 2)
        matrix half{ power(A, b / 2, n) };
        return multiply(half, half, n);
    }
    // 아니다.
    // A^(b - 1) * A
    return multiply(A, power(A, b - 1, n), n);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll b;
    cin >> n >> b;

    matrix A(n, vector<int>(n));
    for (auto& row : A)
    {
        for (auto& val : row)
        {
            cin >> val;
            val %= MOD;
        }
    }

    matrix res{ power(A, b, n) };
    for (const auto& row : res)
    {
        for (const auto& val : row)
        {
            cout << val << " ";
        }
        cout << "\n";
    }


    return 0;
}
