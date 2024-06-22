#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 골드바흐의_추측 6588 Math
// 에라토스테네스의 체 응용, TLE에 유의하자


constexpr int MAX{ 1000000 };


vector<bool> isPrime(MAX + 1, true);
vector<int> primes;

// 에라토스테네스의 체 전처리
void preprocess()
{
    isPrime[0] = isPrime[1] = false;    // 0과 1은 소수가 아님

    // i가 소수인 경우 i의 모든 배수는 소수가 아님
    for (int i = 2; i * i <= MAX; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    // i가 소수인 경우 소수 벡터에 추가
    for (int i = 2; i <= MAX; ++i)
    {
        if (isPrime[i])
        {
            primes.emplace_back(i);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    preprocess();   // 전처리

    int n;

    // n == 0이면 종료
    while (cin >> n && n != 0)
    {
        bool flag{ false }; // 두 소수의 합 존재 여부 플래그

        // a <= n / 2로 a의 값을 제한하여 중복 계산 방지
        for (int i = 0; i < primes.size() && primes[i] <= n / 2; ++i)
        {
            int a{ primes[i] };
            int b{ n - a };

            // b가 소수인가?
            if (binary_search(primes.begin(), primes.end(), b))
            {
                cout << n << " = " << a << " + " << b << "\n";
                flag = true;
                break;
            }
        }

        // n = a + b 꼴의 소수의 합으로 못 나타낼 시
        if (!flag) cout << "Goldbach's conjecture is wrong.\n";
    }
    

    return 0;
}
