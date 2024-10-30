#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 박터뜨리기 19939 Math
// O( 1 )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // 조건에 부합하는 각 바구니에 필요한 
    // 최소 값은 등차수열의 합과 동일
    int minBalls{ k * (k + 1) / 2 };

    // 필요한 최소 공 개수보다 적다면
    // 나눠 담을 수 없음 = 정답 없음 -1
    if (n < minBalls)
    {
        cout << -1;
        return 0;
    }
    // 분배 후 남은 공이 있다면 가장 많이 들어간 바구니에 추가
    // 따라서, 최대값 - 최소값의 차이는 k
    // 남은 공이 없다면, k - 1
    cout << ((n - minBalls) % k ? k : k - 1);


    return 0;
}
