#include <iostream>
#include <vector>

using namespace std;

// 두수의합 3273 HashMap
// 해시맵을 이용한 O(n) 풀이

constexpr int MAX{ 1'000'001 };

int getMatchX(const vector<int>& nums, const vector<bool>& exists, const int x)
{
    int cnt{ 0 };

    for (int n : nums)
    {
        if (x - n > n && x - n <= MAX && exists[x - n])
        {
            ++cnt;
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
    vector<bool> exists(MAX, false);
    for (auto& v : nums)
    {
        cin >> v;
        exists[v] = true;
    }

    int x;
    cin >> x;

    cout << getMatchX(nums, exists, x);
    

    return 0;
}
