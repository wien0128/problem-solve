#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2352 LIS
// LIS 응용, 문제를 잘 읽자.


int lis(vector<int>& port)
{
    vector<int> lis;
    for (int val : port)
    {
        auto iter = lower_bound(lis.begin(), lis.end(), val);

        if (iter == lis.end())
        {
            lis.push_back(val);
        }
        else
        {
            *iter = val;
        }
    }

    return lis.size();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> port(n);
    for (int i = 0; i < n; i++)
    {
        cin >> port[i];
    }
    cout << lis(port) << '\n';

    return 0;
}
