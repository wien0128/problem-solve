#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 포도주시음 31589 TwoPointer


using ll = long long;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<ll> t(n);
    for (ll& wine : t)
    {
        cin >> wine;
    }

    // 오름차순
    sort(t.begin(), t.end());

    // 맛의 최댓값
    ll res{ t[n - 1] };
    // 투 포인터
    int l{ 0 }, r{ n - 2 };
    // 가장 맛있는 포도주를 이미 선택
    --k;

    // 양 끝에서부터 포도주의 최대 맛 차이 계산
    while (k >= 2)
    {
        res += t[r] - t[l];
        ++l;
        --r;
        // 두 개씩 선택
        k -= 2;
    }

    cout << res;


    return 0;
}
