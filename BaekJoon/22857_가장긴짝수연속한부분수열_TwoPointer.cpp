#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 가장긴짝수연속한부분수열 22857 TwoPointer


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> s(n);
    for (int& v : s)
    {
        cin >> v;
    }

    int l{ 0 }, r{ 0 };
    int oddCnt{ 0 };    // 윈도우 내의 홀수 개수
    int maxLen{ 0 };    // 최대 짝수 수열 길이

    while (r < n)
    {   
        // 홀수 체크
        if (s[r] % 2 != 0)
        {
            ++oddCnt;
        }

        // 홀수의 개수가 k보다 커지면
        while (oddCnt > k)
        {
            // 홀수의 개수를 줄임
            if (s[l] % 2 != 0)
            {
                --oddCnt;
            }
            ++l;
        }
        
        // 전체 윈도우 크기에서 홀수 개수 빼기
        maxLen = max(maxLen, r - l + 1 - oddCnt);
        ++r;
    }

    cout << maxLen;


    return 0;
}
