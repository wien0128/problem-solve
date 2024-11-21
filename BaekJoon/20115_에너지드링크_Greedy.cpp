#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 에너지드링크 20115 Greedy
// O( n log n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<double> v(n);
    for (double& e : v) cin >> e;

    // 내림차순
    sort(v.rbegin(), v.rend());

    // 초기값은 가장 많은 에너지 드링크 선택
    double res{ v[0] };
    // 나머지 에너지 드링크는 절반만 추가
    // 내림차순이기에 항상 최적
    for (int i = 1; i < n; ++i)
    {
        res += v[i] / 2;
    }

    cout << fixed << res;


    return 0;
}
