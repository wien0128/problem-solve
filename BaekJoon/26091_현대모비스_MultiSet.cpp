#include <iostream>
#include <set>

using namespace std;
using ll = long long;

// 헌대모비스 26091 MultiSet, BinarySearch
// O( NlogN )

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll m;
    cin >> n >> m;

    multiset<ll> members;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        members.insert(x);
    }

    int teamCnt{ 0 };   // 차출 가능한 팀 개수

    while (!members.empty())
    {
        // 가장 작은 능력치의 멤버 선택
        auto iter1 = members.begin();
        ll stat1 = *iter1;
        members.erase(iter1);   // 삭제

        // 팀 구성 가능한 멤버 찾기
        ll requiredStat = m - stat1;
        auto iter2 = members.lower_bound(requiredStat);

        // 팀을 구성할 수 있다면
        if (iter2 != members.end())
        {
            members.erase(iter2);   // 삭제
            ++teamCnt;  // 차출 가능 팀 개수 증가
        }
    }

    cout << teamCnt;


    return 0;
}
