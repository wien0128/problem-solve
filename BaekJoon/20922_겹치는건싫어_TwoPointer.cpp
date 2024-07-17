#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 겹치는건싫어 20922 TwoPointer
// 같은 원소가 K개 이하로 들어 있는 
// 최장 연속 부분 수열의 길이 구하기


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

    vector<int> cnt(100'001, 0); // 1 <= n <= 10000, 빈도 수
    int l{ 0 }, r{ 0 }; // 투 포인터
    int maxLen{ 0 };    // 부분 수열의 최대 길이

    // 슬라이딩 윈도우
    for (r = 0; r < n; ++r)
    {
        // 현재 숫자 빈도 증가
        ++cnt[arr[r]];

        // 현재 숫자 빈도가 k보다 클 경우
        while (cnt[arr[r]] > k)
        {
            // 현재 숫자 빈도 감소
            --cnt[arr[l]];
            // 포인터 오른쪽 이동
            ++l;
        }

        maxLen = max(maxLen, r - l + 1);
    }

    cout << maxLen;


    return 0;
}
