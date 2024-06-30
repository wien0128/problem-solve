#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 차이를최대로 10819 BruteForce
// 모든 순열을 생성하여 최대 차이값 출력, O(n!)
// 다른 방법도 많지만 이게 가장 직관적이다.


int getMaxSum(vector<int>& arr)
{
    int maxSum{ 0 };

    sort(arr.begin(), arr.end());   // 오름차순

    // 모든 순열 생성 후 최대 차이값 비교 후 대입
    do
    {
        int tmp{ 0 };
        for (size_t i = 1; i < arr.size(); ++i)
        {
            // 차이값을 위해 절대값으로 계산
            tmp += abs(arr[i] - arr[i - 1]);
        }
        maxSum = max(maxSum, tmp);
    } while (next_permutation(arr.begin(), arr.end()));

    return maxSum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& i : arr)
    {
        cin >> i;
    }

    cout << getMaxSum(arr);

    return 0;
}
