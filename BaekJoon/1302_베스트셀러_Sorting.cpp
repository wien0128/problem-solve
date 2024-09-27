#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 베스트셀러 1302 Sorting
// O( N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, int> bookCnt; // [책 이름, 판매량]
    string bookName, res;   // 현재 책, 베스트셀러
    int maxCnt{ 0 };    // 최다 판매량

    for (int i = 0; i < n; ++i)
    {
        cin >> bookName;
        int cnt = ++bookCnt[bookName];  // 책별 카운트 증가

        // 현재 책이 베스트셀러거나,
        // 공동 베스트셀러이면서 사전순으로 더 앞설 경우
        if (cnt > maxCnt || (cnt == maxCnt && bookName < res))
        {
            maxCnt = cnt;
            res = bookName;
        }
    }

    cout << res;

    
    return 0;
}
