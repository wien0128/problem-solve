#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// 백준 1654 Binary Search


// 이분 탐색 구현
ll chopLanCables(vector<ll>& lanCables, ll maxLengthCable, int n)
{
    // 탐색 범위 1 ~ maxLengthCable
    ll start{ 1 }, mid, end{ maxLengthCable };
    ll res{ 0 };

    // 두 포인터가 교차할 때 까지
    while (start <= end)
    {
        // 최대값을 구하기에 (start + end + 1) / 2
        // 최솟값일 경우 (start + end) / 2
        mid = (start + end + 1) / 2;

        // 현재 mid로 잘라서 얻을 수 있는 랜선 수
        ll numCables{ 0 };
        for (auto cable : lanCables)
        {
            numCables += cable / mid;
        }

        if (numCables >= n)
        {
            // 현재 mid로 자른 값이 n보다 크거나 같다면
            // 더 길게 자를 수 있는지?
            start = mid + 1;

            // n개를 만들 수 있을 때, res를 더 큰 값으로 갱신
            res = max(res, mid);
        }
        else
        {
            // 현재 mid로 자른 값이 n보다 작다면
            // 더 짧게 자를 수 있는지?
            end = mid - 1;
        }
    }

    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    cin >> k >> n;

    // 2^31 - 1 = INT_MAX
    vector<ll> lanCables(k);
    ll maxLengthCable{ 0 };

    for (int i = 0; i < k; i++)
    {
        cin >> lanCables[i];
        maxLengthCable = max(maxLengthCable, lanCables[i]);
    }

    cout << chopLanCables(lanCables, maxLengthCable, n);


    return 0;
}
