#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

// 절사평균 6986 Sorting
// 실수오차에 주의...
// O( n log n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<double> scores(n);
    for (double& s : scores) cin >> s;

    // 오름차순
    sort(scores.begin(), scores.end());

    // 절사합계 계산, 하위/상위 k개를 제외한 합계 구하기
    double trimSum = accumulate(scores.begin() + k, scores.end() - k, 0.0);
    // 절사평균 계산, 하위/상위 k개를 제외한 개수로 평균 구하기
    double trimMean = trimSum / (n - 2 * k);

    // 보정평균 계산, 하위/상위 k개를 제외한 수들은 최소값을 k번째 값
    // 최대값을 n-k-1번째 값을 대체 후 k개 만큼 곱한 후 전체 평균 구하기
    double adjMean = (trimSum + k * (scores[k] + scores[n - k - 1])) / n;

    // 소수점 둘째 자리까지 출력
    cout << fixed << setprecision(2)
        << trimMean + 1e-13 << "\n" << adjMean + 1e-13 << "\n";


    return 0;
}
