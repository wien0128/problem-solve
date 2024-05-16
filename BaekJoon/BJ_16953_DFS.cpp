#include <iostream>

using namespace std;
using ll = long long;

// 백준 16953 DFS


void dfs(ll b, int cnt, ll& res, ll a)
{
    if (b == a)     // 변환 성공
    {
        if (res == -1 || res > cnt) 
            res = cnt;
        return;
    }

    // b가 a 보다 작다면 유효한 경로가 아님
    if (b < a) return;

    if (b % 2 == 0)   // b가 짝수인 경우
    {
        // 2로 나눠서 재귀
        dfs(b / 2, cnt + 1, res, a);
    }
    else if (b % 10 == 1)   // b의 1의 자리가 1인 경우
    {
        // b의 1의 자리의 1을 제거하고 재귀
        dfs(b / 10, cnt + 1, res, a);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll a, b;
    cin >> a >> b;

    ll res{ -1 };   // 최소 연산 횟수, 변환 실패 시 -1
    dfs(b, 1, res, a);

    cout << res;


    return 0;
}
