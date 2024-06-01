#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

// 백준 1300 Binary Search
// 아이디어 떠올리기 굉장히 까다로웠던 문제

// Main Idea
// 1. k라는 수보다 작거나 같은 수가 k개 존재한다.
// 2. 1~n을 t로 나눴을 때의 값이 t보다 작거나 같은 수의 개수이다.


// mid 보다 작거나 같은 수의 개수
ll cntBelowMid(ll n, ll mid)
{
    ll cnt{ 0 };
    for (int i = 1; i <= n; i++)
    {
        // = i번째 행에서 mid 보다 작거나 같은 수의 개수
        cnt += min((mid / i), n);
    }
    return cnt;
}

// 이분 탐색
ll getKth(ll n, ll k)
{
    // n * n도 가능하지만, B[k] < k 항상 참이다. 
    ll left{ 1 }, mid, right{ k };
    ll res{ 0 };

    while (left <= right)
    {
        mid = (left + right) / 2;

        // mid 보다 작거나 같은 수의 개수가
        // B[k]보다 작은가?
        if (cntBelowMid(n, mid) < k)
        {
            // 작다.
            // B[k]가 mid보다 크다.
            left = mid + 1;
        }
        else
        {
            // 크다.
            // B[k]가 mid보다 작거나 같다.
            res = mid;
            right = mid - 1;
        }
    }

    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, k;
    cin >> n >> k;

    cout << getKth(n, k) << "\n";

    return 0;
}
