#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// 백준 2805 Binary Search
// m 을 만족하는 절단기의 최대 높이 값이 정답


// 이분 탐색
ll chopTrees(vector<ll>& trees, ll maxHeightTree, ll m)
{
    ll start{ 1 }, mid, end{ maxHeightTree };
    ll res{ 0 };

    while (start <= end)
    {
        // 최대값 (start + end + 1) / 2
        // 최소값 (start + end) / 2
        mid = (start + end + 1) / 2;

        // 현재 mid로 자른 나무의 총 길이
        ll cutTreeLength{ 0 };
        for (auto tree : trees)
        {
            // 현재 tree가 자를 길이 mid 보다 긴가?
            if (mid < tree)
            {
                // 베어서 얻을 수 있는 나무의 길이
                cutTreeLength += tree - mid;
            }
            if (cutTreeLength > m)
            {
                // 베어낸 나무가 m 초과 시 종료
                break;
            }
        }

        // 베어낸 나무 길이가 m 을 만족하는가?
        if (cutTreeLength >= m)
        {
            // 최적해를 위해 더 길게 자르기
            start = mid + 1;
            // m을 만족하는 절단기 높이의 최댓값 중 가장 큰 값
            res = max(res, mid);
        }
        else
        {
            // 더 짧은 길이로 자르기
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

    ll n, m;
    cin >> n >> m;

    vector<ll> trees(n);
    ll maxHeightTree{ 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
        maxHeightTree = max(maxHeightTree, trees[i]);
    }

    cout << chopTrees(trees, maxHeightTree, m) << "\n";


    return 0;
}
