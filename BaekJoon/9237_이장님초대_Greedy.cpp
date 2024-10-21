#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이장님초대 9237 Greedy
// O( N log N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int& e : v)
    {
        cin >> e;
    }

    // 묘목 내림차순 정렬
    sort(v.rbegin(), v.rend());

    int res{ 0 };
    for (int i = 0; i < n; ++i)
    {
        // i번째 묘목을 심은 후 다 자라는 날짜
        res = max(res, v[i] + i);
    }

    // 묘목이 다 자란 후 초대하기에 +2
    cout << res + 2;


    return 0;
}
