#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

// 두수의합 9024 TwoPointer
// k 에 가장 가까운 두 수의 합의 개수
// O( T * nlogn )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int& x : arr)
        {
            cin >> x;
        }

        // 오름차순
        sort(arr.begin(), arr.end());

        int l{ 0 }, r{ n - 1 }; // 투 포인터
        int closestDiff{ numeric_limits<int>::max() };  // k 에 가장 가까운 합의 차이
        int cnt{ 0 };   // k 에 가장 가까운 쌍의 개수

        while (l < r)
        {
            int curSum = arr[l] + arr[r];   // 현재 두 수의 합
            int curDiff = abs(curSum - k);  // 현재 합과 k 의 차이

            // 현재 차이가 더 작은 경우
            if (curDiff < closestDiff)
            {
                closestDiff = curDiff;
                cnt = 1;
            }
            // 현재 차이가 가장 가까운 차이와 같은 경우
            else if (curDiff == closestDiff)
            {
                cnt++;
            }

            // 현재 합이 k 보다 작다면
            if (curSum < k)
            {
                ++l;    // 현재 합을 크게
            }
            else
            {
                --r;    // 현재 합을 작게
            }
        }

        cout << cnt << "\n";
    }


    return 0;
}
