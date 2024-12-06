#include <iostream>
#include <string>

using namespace std;

// 비밀번호발음하기 4659 Implement, String
// 출력 형식을 잘 보자
// O( N * str.length() )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // isVowel[ch] = 자음 0, 모음 1
    bool isVowel[128] = {};
    for (char ch : "aeiou") isVowel[ch] = true;
    
    string str;

    while (cin >> str && str != "end")
    {
        bool hasVowel{ false };         // 모음 포함 여부
        bool isAcceptable{ true };      // 유효 비밀번호 여부
        int vowelCnt{ 0 }, cvCnt{ 0 };  // 연속된 모음/자음 개수
        char prevChar{ '\0' };          // 이전 문자

        // 각 문자에 대해 조건 검사
        for (char ch : str)
        {
            // 조건 1: 모음을 포함하는가?
            // 조건 2: 연속되는 모음/자음의 개수가 3개를 초과하는가?
            if (isVowel[ch])
            {
                hasVowel = true;    // 모음을 포함
                ++vowelCnt;
                cvCnt = 0;
            }
            else
            {
                ++cvCnt;
                vowelCnt = 0;
            }
            if (vowelCnt >= 3 || cvCnt >= 3)
            {
                isAcceptable = false;
                break;
            }

            // 조건 3: 중복으로 연속되는 문자인가? (ee, oo 제외)
            if (prevChar == ch && ch != 'e' && ch != 'o')
            {
                isAcceptable = false;
                break;
            }

            // 이전 문자 갱신
            prevChar = ch;
        }

        // 조건 검사 후 조건 1 확인
        if (!hasVowel) isAcceptable = false;

        cout << "<" << str << "> is "
            << (isAcceptable ? "acceptable.\n" : "not acceptable.\n");
    }


    return 0;
}
