#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 스네이크버드 16435 Sorting
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

    // 오름차순
    sort(v.begin(), v.end());

    for (int& e : v)
    {
        // 먹을 수 없는 과일이 나올 경우
        if (e > l) break;
        l++;
    }

    cout << l;


    return 0;
}
