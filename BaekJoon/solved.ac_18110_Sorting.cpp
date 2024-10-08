#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

// solved.ac 18110 Sorting
// 구현은 간단하지만 캐스팅에 주의
// O( n log n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    vector<int> v(n);
    for (int& e : v)
    {
        cin >> e;
    }

    // 오름차순
    sort(v.begin(), v.end());

    // 15%에 해당하는 평가 수, 반올림 계산
    double exc = round(n * 0.15);
    // 하위 15% 직후부터 상위 15% 직전까지 모두 더하기
    // 초기값은 0
    int sum{ accumulate(v.begin() + exc, v.end() - exc, 0) };
    // 상하위 15%를 제외한 점수들의 평균
    double res{ (sum) / (n - 2 * exc) };

    // 결과값 반올림 하여 출력
    cout << round(res);


    return 0;
}
