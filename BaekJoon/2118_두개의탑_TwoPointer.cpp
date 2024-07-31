#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// 두개의탑 2118 TwoPointer
// O( n + 2n ) = O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int totalSum{ 0 };          // 총 거리 합
    vector<int> dist(2 * n);    // 원형 배열 거리값
    for (int i = 0; i < n; ++i)
    {
        cin >> dist[i];
        totalSum += dist[i];
        dist[i + n] = dist[i];
    }

    int sum{ 0 };       // 포인터 사이 거리 합
    int maxDist{ 0 };   // 최대 거리

    // 투 포인터
    for (int l = 0, r = 0; l < n; ++l)
    {
        // 포인터 사이의 거리가 반원(전체 거리의 절반)일 때까지
        while (sum * 2 < totalSum)
        {
            sum += dist[r++];
        }
        // 최대 거리 갱신: max(현재 최대 거리, 포인터 사이 거리)
        maxDist = max(maxDist, min(sum, totalSum - sum));
        sum -= dist[l];
    }

    cout << maxDist;


    return 0;
}
