#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// K번째수 11004 Sorting
// O( N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int& e : v) cin >> e;

    // 부분 정렬
    nth_element(v.begin(), v.begin() + k - 1, v.end());

    cout << v[k - 1] << "\n";


    return 0;
}
