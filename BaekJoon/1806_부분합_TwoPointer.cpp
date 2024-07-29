#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// 부분합 1806 TwoPointer
// S 이상인 부분합 중 가장 짧은 것 구하기
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> nums(n);
    for (int& x : nums)
    {
        cin >> x;
    }

    int l{ 0 }, r{ 0 }; // 투 포인터
    int sum{ 0 };   // 현재 부분합
    int minLen{ numeric_limits<int>::max() }; // 최소 길이 

    while (r <= n)
    {
        // 현재 부분합이 s 이상일 경우
        if (sum >= s)
        {
            // 현재 윈도우의 길이와 최소 길이 비교
            minLen = min(minLen, r - l);
            // l 포인터 값 빼고 오른쪽 이동
            sum -= nums[l++];
        }
        // 현재 부분합이 s 미만일 경우
        else
        {
            // r 포인터 값 더하고 오른쪽 이동
            if (r < n)
            {
                sum += nums[r];
            }
            ++r;
        }
    }

    // 최소 길이를 못 찾았다면
    if (minLen == numeric_limits<int>::max())
    {
        cout << 0;
    }
    else
    {
        cout << minLen;
    }


    return 0;
}
