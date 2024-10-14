#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 좋은구간 1059 Math, Sorting
// O( N log N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int l, n;
    cin >> l;

    vector<int> s(l);
    for (int& e : s)
    {
        cin >> e;
    }
    cin >> n;

    sort(s.begin(), s.end());

    // n이 집합 s에 존재하면 좋은 구간은 없음
    if (binary_search(s.begin(), s.end(), n))
    {
        cout << 0;
        return 0;
    }

    auto idx{ upper_bound(s.begin(), s.end(), n) };
    int right{ *idx };          // n보다 큰 첫 번째 수
    int left{ *(idx - 1) };     // n보다 작은 마지막 수

    // (n - left - 1) = left보다 크고 n보다 작은 수의 개수
    // (right - n) = n보다 크고 right보다 작은 수의 개수
    // (n - left - 1) * (right - n) = left < n < right 구간의 모든 
    //                                경우의 수
    // (right - n - 1) = n보다 크고 right보다 작은 구간에서 n만 
    //                   포함하고 left는 포함하지 않는 경우의 수
    int res = (n - left - 1) * (right - n) + (right - n - 1);
    cout << res;


    return 0;
}
