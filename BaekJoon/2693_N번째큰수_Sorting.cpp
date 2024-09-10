#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

// N번째큰수 2693 Sorting
// O( N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        array<int, 10> nums;
        for (int& num : nums) cin >> num;

        nth_element(nums.begin(), nums.begin() + 2, nums.end(), greater<>());
        
        cout << nums[2] << "\n";
    }


    return 0;
}
