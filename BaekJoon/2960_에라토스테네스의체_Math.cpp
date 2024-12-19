#include <iostream>
#include <vector>

using namespace std;

// 에라토스테네스의체 2960 Math
// O( n log n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // 소수 여부 벡터
    vector<bool> isPrime(n + 1, true);
    // 제거된 숫자 개수 카운터
    int cnt{ 0 };

    for (int i = 2; i <= n; ++i)
    {
        // 소수가 아닌 수는 건너뜀
        if (!isPrime[i]) continue;

        // i의 배수들 탐색
        // i^2에서 시작하면 제대로된 카운팅이 불가함
        for (int j = i; j <= n; j += i)
        {
            // 이미 소수가 아닌 수는 건너뜀
            if (!isPrime[j]) continue;
            // 해당 숫자 제거
            isPrime[j] = false;

            // k번째로 제거된 수라면 출력
            if (++cnt == k)
            {
                cout << j << "\n";
                return 0;
            }
        }
    }


    return 0;
}
