#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 12015 LIS
// DP = O(N^2)
// BinarySearch = O(NlogN)

// 사전지식이 없다면 굉장히 어려웠을 법한 문제
// LIS 배열의 값이 아닌 길이만을 알 수 있음


int lis(vector<int>& a)
{
    vector<int> dp;

    for (int i = 0; i < a.size(); i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);

        if (it == dp.end())
        {
            dp.push_back(a[i]);
        }
        else
        {
            *it = a[i];
            // *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        }
    }

    return dp.size();
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

    cout << lis(a);


    return 0;
}
