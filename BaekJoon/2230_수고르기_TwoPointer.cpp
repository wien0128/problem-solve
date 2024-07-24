#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 수고르기 2230 TwoPointer
// 수열에서 차이가 M 이상이면서 제일 
// 작은 경우의 두 수를 구하는 문제


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int& a : arr)
    {
        cin >> a;
    }

    // 오름차순
    sort(arr.begin(), arr.end());

    int l{ 0 }, r{ 0 }; // 투 포인터
    int minDiff = numeric_limits<int>::max();   // 최소 차이 변수

    // 슬라이딩 윈도우
    while (r < n)
    {
        // 현재 차이 값
        int tmp = arr[r] - arr[l];

        // 현재 차이가 m 이상인 경우
        if (tmp >= m)
        {
            minDiff = min(minDiff, tmp);
            if (minDiff == m) break;
            ++l;
        }
        else
        {
            ++r;
        }
    }

    cout << minDiff;


    return 0;
}
