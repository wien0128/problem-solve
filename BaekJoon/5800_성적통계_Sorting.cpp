#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 성적통계 5800 Sorting
// O( K * N logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k;

    for (int i = 1; i <= k; ++i)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int& e : v)
        {
            cin >> e;
        }

        sort(v.begin(), v.end());

        int gap{ 0 };
        for (int j = 1; j < n; ++j)
        {
            gap = max(gap, v[j] - v[j - 1]);
        }

        cout << "Class " << i << "\n";
        cout << "Max " << v.back() << ", Min " << v.front() <<
            ", Largest gap " << gap << "\n";
    }


    return 0;
}
