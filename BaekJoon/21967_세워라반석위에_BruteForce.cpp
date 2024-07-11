#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 세워라반석위에 21967 BruteForce
// O( N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& a : arr)
    {
        cin >> a;
    }

    int maxLen{ 0 };    // 가장 긴 반석의 길이

    for (int i = 1; i <= 10; ++i)
    {
        int cur{ 0 };   // 현재 반석의 길이
        for (int& a : arr)
        {
            if (a > i - 2 && a < i + 2)
            {
                ++cur;
            }
            else
            {
                cur = 0;
            }
            maxLen = max(maxLen, cur);
        }
    }

    cout << maxLen;


    return 0;
}
