#include <iostream>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

// 펠린드롬 1213 Greedy, String
// O( N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input;
    cin >> input;

    // 알파벳 빈도 수 고정 배열
    array<int, 26> cnt{};

    // 알파벳 별 빈도 확인
    for (char c : input)
    {
        ++cnt[c - 'A'];
    }

    // 문자열 절반 
    // 홀수 개 알파벳 = 중앙의 문자, 이외 경우는 펠린드롬 못 만듦
    string half, middle;
    for (int i = 0; i < 26; ++i)
    {
        // 현재 알파벳이 홀수 개라면
        if (cnt[i] % 2)
        {
            // 이미 홀수 개의 알파벳이 존재한다면
            // = 홀수 개의 알파벳은 하나만 존재해야 펠린드롬 성립
            if (!middle.empty())
            {
                cout << "I'm Sorry Hansoo\n";
                return 0;
            }
            // 현재 홀수 개 알파벳 하나 저장
            middle = string(1, char(i + 'A'));
        }
        // 현재 알파벳의 절반만큼 추가
        half += string(cnt[i] / 2, char(i + 'A'));
    }

    // = 절반 + 홀수 개의 알파벳 + 절반의 역순
    cout << half + middle + string(half.rbegin(), half.rend());

    
    return 0;
}
