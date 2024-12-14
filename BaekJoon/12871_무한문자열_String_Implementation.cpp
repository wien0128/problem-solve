#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

// 무한문자열 12871 String, Implementation
// 최소공배수 길이 내에서 같다면 동일한 패턴
// 다르다면, 다른 패턴 ("ab", "abab")
// O( n * m )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int sLen{ s.size()};
    int tLen{ t.size() };

    // 두 문자열의 최소 공배수
    // = 동일한 패턴을 보이는 가장 짧은 반복 길이
    int lcmLen{ lcm(s.size(), t.size()) };

    // 최소 공배수만큼 문자열 반복 비교
    // = 다르다면, 두 문자열은 다르게 반복되는 것
    // = 동일하다면, 두 문자열은 동일하게 반복되는 것
    for (int i = 0; i < lcmLen; ++i)
    {
        if (s[i % sLen] != t[i % tLen])
        {
            cout << 0;
            return 0;
        }
    }
    cout << 1;


    return 0;
}
