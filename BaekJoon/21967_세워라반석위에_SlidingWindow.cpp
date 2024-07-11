#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 세워라반석위에 21967 SlidingWindow
// O( NlogN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& a : arr)
    {
        cin >> a;
    }

    int l{ 0 };         // 투 포인터
    int maxLen{ 0 };    // 가장 긴 반석의 길이
    multiset<int> window;   // 슬라이딩 윈도우

    for (int r = 0; r < n; ++r)
    {
        window.insert(arr[r]);

        // 최댓값 - 최솟값 > 2
        while (*window.rbegin() - *window.begin() > 2)
        {
            // 왼쪽 원소 지우기
            window.erase(window.find(arr[l]));
            // 윈도우 오른쪽으로 이동
            ++l;
        }

        // 현재 윈도우 갱신
        maxLen = max(maxLen, r - l + 1);
    }

    cout << maxLen;

    return 0;
}
