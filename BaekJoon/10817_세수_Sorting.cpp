#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

// 세수 10817 Sorting
// O( N logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    array<int, 3> arr;

    for (int& x : arr) cin >> x;

    sort(arr.begin(), arr.end());

    cout << arr[1];


    return 0;
}
