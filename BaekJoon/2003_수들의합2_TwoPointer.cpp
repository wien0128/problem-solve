#include <iostream>
#include <vector>

using namespace std;

// 수들의합2 2003 TwoPointer
// (sum == m) = (arr[start] + ... + arr[end] == m), 같은 뜻이다.


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (auto& i : arr)
    {
        cin >> i;
    }

    // 투 포인터
    int start{ 0 };
    // m이 되는 부분 수열의 개수, 현재 부분 수열의 합
    int cnt{ 0 }, sum{ 0 };

    
    for (int end = 0; end < n; ++end)
    {
        sum += arr[end];

        // 탐색 범위 축소
        while (sum > m) 
        {
            sum -= arr[start++];
        }
        // m이 되는 부분 수열 발견 했다면
        if (sum == m)
        {
            ++cnt;
        }
    }

    cout << cnt;


    return 0;
}
