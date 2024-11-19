#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 대표자연수 2548 Sorting
// 문제를 꼼꼼히 읽자
// O( n log n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& num : nums) cin >> num;

    // 오름차순
    sort(nums.begin(), nums.end());

    // 대표값 == 중앙값
    // 모든 원소들로 부터의 거리 합을 최소화하는 값
    cout << nums[n / 2 - (n % 2 == 0)];


    return 0;
}
