#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// 헌대모비스 26091 TwoPointer
// O( NlogN )

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll m;
    cin >> n >> m;

    vector<ll> members(n);
    for (ll& member : members)
    {
        cin >> member;
    }

    sort(members.begin(), members.end());   // 오름차순

    int l{ 0 }, r{ n - 1 }; // 투 포인터
    int teamCnt{ 0 };       // 차출 가능한 팀 개수

    while (l < r)
    {
        // l, r 포인터의 합이 m보다 크거나 같다면
        if (members[l] + members[r] >= m)
        {
            // 투 포인터 이동
            ++l;
            --r;
            ++teamCnt; // 차출 가능 팀 개수 증가
        }
        else
        {
            ++l; // 합이 m보다 작다면, l 포인터를 더 큰 값으로 이동
        }
    }

    cout << teamCnt;


    return 0;
}
