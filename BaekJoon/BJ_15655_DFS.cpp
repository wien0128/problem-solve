#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// BJ 15655 DFS


void dfs(vector<int>& nums, vector<int>& seq, int m, int index)
{
    if (m == 0)
    {
        for (int num : seq)
        {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        seq.push_back(nums[i]);

        dfs(nums, seq, m - 1, i + 1);

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

    dfs(nums, seq, m, 0);


    return 0;
}
