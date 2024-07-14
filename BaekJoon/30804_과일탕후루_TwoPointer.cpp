#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 과일탕후루 30804 TwoPointer


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> tanghuru(n);
    for (int& t : tanghuru)
    {
        cin >> t;
    }

    vector<int> fruitCnt(10, 0); // 과일 번호 벡터 (1 ~ 9)
    int l{ 0 }, r{ 0 };          // 투 포인터
    int maxLen{ 0 };             // 두 종류 이하로 이뤄진 가장 긴 부분 배열 길이
    int distinctCnt{ 0 };        // 현재 윈도우 내의 과일 종류 개수

    while (r < n)
    {
        // 윈도우에 처음 추가되는 과일인가?
        if (fruitCnt[tanghuru[r]] == 0)
        {
            // 과일 종류 개수 증가
            ++distinctCnt;
        }
        ++fruitCnt[tanghuru[r]];    // 해당 과일 개수 증가
        ++r;

        // 과일 종류가 2종류 이상인가?
        while (distinctCnt > 2)
        {
            // l 포인터 과일 개수 감소
            --fruitCnt[tanghuru[l]];
            // 해당 과일의 개수가 0개인가?
            if (fruitCnt[tanghuru[l]] == 0)
            {
                // 과일 종류 개수 감소
                --distinctCnt;
            }
            ++l;
        }

        // 과일 종류가 2개 이하인 부분 배열 갱신
        maxLen = max(maxLen, r - l);
    }

    cout << maxLen;


    return 0;
}
