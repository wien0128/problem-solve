#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 수리공항승 1449 Sorting
// 테이프로 커버하는 범위만 생각하면 쉬운 문제
// O( N log N )

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, l;
    cin >> n >> l;

    vector<int> v(n);
    for (int& e : v) cin >> e;

    // 오름차순 정렬
    sort(v.begin(), v.end());

    int tapes{ 1 };             // 첫 테이프는 항상 사용
    int cvg{ v[0] + l - 1 };    // 첫 테이프의 커버리지 끝 인덱스

    for (int i = 1; i < n; ++i)
    {
        // 현재 커버리지로 누수 지점을 커버 불가능하다면
        if (v[i] > cvg)
        {
            ++tapes;            // 새 테이프 사용
            cvg = v[i] + l - 1; // 커버리지 갱신
        }
    }

    cout << tapes;


    return 0;
}
