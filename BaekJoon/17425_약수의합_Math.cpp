#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MAX{ 1000000 };

// 약수의_합 17425 Math
// 전처리가 핵심인 에라토스테네스의 체 문제
// x가 y의 배수이면 y는 x의 약수


vector<ll> dp(MAX + 1, 0); // dp[i] = i의 약수의 합

void preprocess()
{
    // 인덱스별 약수의 합
    for (int i = 1; i <= MAX; ++i)
    {
        for (int j = i; j <= MAX; j += i)
        {
            dp[j] += i;     // j의 약수인 i
        }
        dp[i] += dp[i - 1]; // 인덱스별 약수의 합 누적
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    preprocess();   // 전처리

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << dp[n] << "\n";
    }
    

    return 0;
}
