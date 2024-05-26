#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// BJ 12904 Greedy
// 역발상이 중요한 문제
// 마지막 문자가 A, B는 각 한 가지 방법만 존재
// 지우거나 지우고 뒤집거나
// 따라서 그리디 문제이다


// T -> S
bool isConvertTtoS(string& S, string& T)
{
    while (T.size() > S.size()) // 길이가 같을 때까지
    {
        // A = 마지막 문자 삭제
        // B = 마지막 문자 삭제 && 문자열 뒤집기
        if (T.back() == 'A')
        {
            T.pop_back();
        }
        else
        {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }
    return (T == S);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S, T;
    cin >> S >> T;

    cout << isConvertTtoS(S, T);


    return 0;
}
