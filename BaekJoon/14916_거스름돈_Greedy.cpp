#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 거스름돈 14916 Greedy
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if (n == 1 || n == 3)
    {
        cout << -1;
        return 0;
    }

    // 5원 동전을 최대한 사용 후 2원으로 처리
    int cnt{ n / 5 };
    int remain{ n % 5 };

    // 5원으로 나눈 나머지 금액 2원 동전으로 나누어 질 때까지
    while (remain % 2 != 0 && cnt > 0)
    {
        --cnt;          // 5원 동전 하나 줄이기
        remain += 5;    // 나머지 5원 증가
    }

    // 남은 금액이 2원으로 나누어떨어진다면
    if (remain % 2 == 0)
    {
        // 5원 동전 개수 + 2원 동전 개수
        cout << cnt + (remain / 2);
    }
    else
    {
        cout << -1;
    }

    
    return 0;
}
