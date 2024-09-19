#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 수정렬하기4 11931 Sorting
// O( N logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int& e : v) cin >> e;

    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
        });

    for (const int& e : v)
    {
        cout << e << "\n";
    }


    return 0;
}
