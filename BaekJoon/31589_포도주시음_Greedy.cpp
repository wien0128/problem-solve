#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 포도주시음 31589 Greedy


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
    ll res{ 0 };
    // 가장 맛있는 포도주 선택
    for (int i = 0; i < (k + 1) / 2; ++i)
    {
        // 벡터 맨 끝부터 선택
        res += t[n - i - 1];
    }
    // 가장 맛없는 포도주 선택
    for (int i = 0; i < (k - 1) / 2; ++i)
    {
        res -= t[i];
    }

    cout << res;


    return 0;
}
