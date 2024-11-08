#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 안테나 18310 Greedy, Sorting
// 모든 집들과의 최소 거리 합 = 중앙값
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

    // 오름차순
    sort(v.begin(), v.end());

    // 중앙값
    // 홀수, 짝수 구분할 필요 없음
    cout << v[(n - 1) / 2];


    return 0;
}
