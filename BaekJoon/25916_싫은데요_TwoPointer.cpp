#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// 싫은데요 25916 TwoPointer

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll m;
    cin >> n >> m;

    vector<ll> holes(n);
    for (ll& hole : holes)
    {
        cin >> hole;
    }

    ll curSum{ 0 }; // 현재 선택된 구멍들의 비용 총합
    ll maxVolume{ 0 }; // 현재 최대 부피
    int l{ 0 };

    for (int r = 0; r < n; ++r)
    {
        // 선택된 구멍들의 비용 더하기
        curSum += holes[r];

        // curSum이 m을 초과한다면, l 포인터 오른쪽 이동
        while (curSum > m)
        {
            curSum -= holes[l++];
        }

        // curSum이 m 이하일 때, 최대 부피 갱신
        if (curSum <= m)
        {
            maxVolume = max(maxVolume, curSum);
        }
    }

    cout << maxVolume;


    return 0;
}
