#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 두수의합 3273 TwoPointer
// 제네럴한 투 포인터 문제
// 오름차순 정렬 후 양끝부터 탐색


int getMatchX(const vector<int>& nums, const int x)
{
    // 투 포인터
    int start{ 0 }, end{ (int)nums.size() - 1 };
    // x가 되는 쌍의 개수
    int cnt{ 0 };

    while (start < end)
    {
        // 현재 포인터가 가리키는 수의 합
        int curSum = nums[start] + nums[end];
        
        if (curSum == x)
        {
            ++cnt;
            ++start;
            --end;
        }
        else if (curSum < x)
        {
            ++start;
        }
        else
        {
            --end;
        }
    }

    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto& v : nums)
    {
        cin >> v;
    }
    sort(nums.begin(), nums.end()); // 오름차순

    int x;
    cin >> x;

    cout << getMatchX(nums, x);
    

    return 0;
}
