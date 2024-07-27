#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 가장긴짝수연속한부분수열 22862 TwoPointer
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int& a : arr)
    {
        cin >> a;
    }

    int l{ 0 }, r{ 0 }; // 투 포인터
    int maxLen{ 0 };    // 최장 짝수 연속 부분 수열 길이
    int oddCnt{ 0 };    // 홀수 개수 카운터

    while (r < n)
    {
        // 현재 r 포인터의 수가 홀수라면
        if (arr[r] % 2 != 0)
        {
            ++oddCnt;
        }

        // 홀수 개수가 삭제 가능 횟수 초과라면
        while (oddCnt > k)
        {
            // 현재 l 포인터의 수가 홀수라면
            if (arr[l] % 2 != 0)
            {
                --oddCnt;
            }
            ++l;
        }

        // 현재 윈도우 크기 - 홀수 개수
        maxLen = max(maxLen, r - l + 1 - oddCnt);
        ++r;
    }

    cout << maxLen;


    return 0;
}
