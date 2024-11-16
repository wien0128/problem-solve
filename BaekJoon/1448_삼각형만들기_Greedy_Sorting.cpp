#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 삼각형만들기 1448 Greedy, Sorting
// O( n log n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int& e : v) cin >> e;

    // 내림차순
    sort(v.rbegin(), v.rend());

    // 내림차순이기에 가장 긴 길이 부터 조건 학인
    for (int i = 0; i < n - 2; ++i)
    {
        // 삼각형 성립 조건
        // = 가장 긴 변 < 나머지 두 변의 합
        if (v[i] < v[i + 1] + v[i + 2])
        {
            cout << v[i] + v[i + 1] + v[i + 2];
            return 0;
        }
    }

    cout << -1;


    return 0;
}
