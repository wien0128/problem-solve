#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// MaximumSubarray 10211 Prefix-Sum
// 카데인 알고리즘
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int curSum, maxSum;
        cin >> curSum;
        maxSum = curSum;

        for (int i = 1, x; i < n; ++i)
        {
            cin >> x;
            curSum = max(x, curSum + x);
            maxSum = max(maxSum, curSum);
        }

        cout << maxSum << '\n';
        
    }


    return 0;
}
