#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// 귀여운라이언 15565 TwoPointer
// 라이언 인형(1)이 K개 이상 있는 가장 작은 
// 연속된 인형(1, 2)들의 집합의 크기 구하기

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> dolls(n);
    for (int& doll : dolls)
    {
        cin >> doll;
    }

    int l{ 0 }, r{ 0 }; // 투포인터
    int lionCnt{ 0 };   // 라이언 인형의 개수
    // 라이언 인형을 K개 이상 가진 가장 작은 연속 집합의 크기
    int minLen{ numeric_limits<int>::max() };

    // 슬라이딩 윈도우
    while (r < n)
    {
        // 현재 포인터 r이 라이언 인형이라면
        if (dolls[r++] == 1)
        {
            // 개수 증가 후 포인터 r 오른쪽 이동
            ++lionCnt;
        }

        // 라이언 인형의 개수가 K개 이상이라면
        while (lionCnt >= k)
        {
            // 최소 집합의 크기 계산
            minLen = min(minLen, r - l);
            
            // 현재 포인터 l이 라이언 인형이라면
            if (dolls[l++] == 1)
            {
                // 개수 감소 후 포인터 l 오른쪽 이동
                --lionCnt;
            }
        }
    }

    if (minLen == numeric_limits<int>::max())
    {
        cout << -1;
    }
    else
    {
        cout << minLen;
    }


    return 0;
}
