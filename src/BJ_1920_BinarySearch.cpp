#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 1920 Binary Search


bool binary_search(vector<int>& v, int target, int left, int right)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (v[mid] == target)
        {
            return true;
        }
        else if (v[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        cout << binary_search(v, num, 0, n - 1) << "\n";
    }


    return 0;
}
