#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 수정렬하기5 15688 Sorting
// 빠른 입출력 문제
// O( N log N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int& e : v) cin >> e;

    sort(v.begin(), v.end());

    for (int& e : v) cout << e << "\n";


    return 0;
}
