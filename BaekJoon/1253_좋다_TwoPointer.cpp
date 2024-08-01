#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 좋다 1253 TwoPointer
// 두 수의 합이 특정 수가 되는지 찾는 문제
// O( nlogn ) + O( n^2 ) => O( n^2 )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums)
    {
        cin >> x;
    }

    // 오름차순
    sort(nums.begin(), nums.end());

    int cnt{ 0 };   // GOOD 카운터

    // 타겟 요소 순회 검사
    for (int target = 0; target < n; ++target)
    {   
        // 투 포인터
        int l = 0, r = n - 1;

        while (l < r)
        {
            // 포인터들이 target 과 겹치면 건너뜀
            // 1. 동일 수 중복 선택 방지
            // 2. 다른 인덱스 선택 보장
            if (l == target) { ++l; continue; } 
            if (r == target) { --r; continue; }

            // 두 포인터 값의 합
            int sum = nums[l] + nums[r];

            // target 값과 같다면 카운터 증가 후 break
            if (sum == nums[target]) { ++cnt; break; }

            // 위 조건식에 포함되지 않는다면 포인터 조정
            if (sum < nums[target])
                ++l;
            else
                --r;
        }
    }
    
    cout << cnt;


    return 0;
}
