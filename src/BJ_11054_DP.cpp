#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 11054 DP
// LIS + LDS - 1 = LBS


int lbs(vector<int>& a)
{
    int n = a.size();
    vector<int> dp_lis(n, 1), dp_lds(n, 1);


    // LongestIncreasing Subsequence
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp_lis[i] = max(dp_lis[i], dp_lis[j] + 1);
            }
        }
    }

    // Longest Decreasing Subsequence
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[i])
            {
                dp_lds[i] = max(dp_lds[i], dp_lds[j] + 1);
            }
        }
    }

    int maxLength{ 0 };
    for (int i = 0; i < n; i++)
    {
        // LIS + LSD - 1 (중복 제거)
        maxLength = max(maxLength, dp_lis[i] + dp_lds[i] - 1);
    }

    return maxLength;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << lbs(a);


    return 0;
}
