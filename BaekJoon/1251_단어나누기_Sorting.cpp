#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 단어나누기 1251 Sorting
// O( N^3 )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string word;
    cin >> word;

    int len = word.length();
    string res = "~";   // 아스키 기반 가장 큰 값

    // 두 번을 나누면 삼등분을 이룬다
    for (int i = 1; i < len - 1; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            string p1 = word.substr(0, i);
            string p2 = word.substr(i, j - i);
            string p3 = word.substr(j);

            reverse(p1.begin(), p1.end());
            reverse(p2.begin(), p2.end());
            reverse(p3.begin(), p3.end());

            string str = p1 + p2 + p3;

            res = min(res, str);
        }
    }

    cout << res;


    return 0;
}
