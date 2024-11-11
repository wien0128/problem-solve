#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 등수매기기 2012 Greedy, Sorting
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

    long long res{ 0 }; // 대략 최대 2500억까지
    for (int i = 0; i < n; ++i)
    {
        res += abs(v[i] - (i + 1));
    }

    cout << res;


    return 0;
}
