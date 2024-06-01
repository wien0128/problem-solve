#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// BJ 15654 Brute-Force BackTracking


void dfs(vector<int>& nums, int m, vector<int>& seq)
{
    if (seq.size() == m)
    {
        for (int num : seq)
        {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        seq.push_back(nums[i]);

        vector<int> next_nums = nums;
        next_nums.erase(next_nums.begin() + i);
        
        dfs(next_nums, m, seq);

        seq.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    vector<int> seq;

    dfs(nums, m, seq);


    return 0;
}