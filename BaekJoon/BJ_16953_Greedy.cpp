#include <iostream>

using namespace std;
using ll = long long;

// 백준 16953 Greedy
// DFS, Greedy, Recursion 등 다양한 풀이가 존재
// A -> B가 아닌 B -> A로 생각하면 한결 쉬워진다


int greedy(ll a, ll b)
{
    int cnt{ 1 };
    while (a < b)
    {
        // (b가 홀수? && 1로 끝남?) || b가 a보다 작은가?
        // 변환 불가능
        if ((b % 2 != 0 && b % 10 != 1) || b < a) return -1;
        
        if (b % 2 == 0) // b가 짝수일 경우
        {
            b /= 2; // 2로 나눔
        }
        else if (b % 10 == 1) // b가 1로 끝날 경우
        {
            b /= 10; // 1의 자리 제거
        }

        cnt++;  // 연산 횟수 증가
    }

    // 루프가 끝나도 정답을 못 구했다면 변환 불가능
    return a != b ? -1 : cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll a, b;
    cin >> a >> b;

    cout << greedy(a, b);


    return 0;
}
