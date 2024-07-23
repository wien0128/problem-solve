#include <iostream>
#include <string_view>

using namespace std;

// 회문 17609 TwoPointer
// 회문과 유사회문을 판별해야 하는 문제


/**
* @brief 주어진 문자열이 회문 또는 유사회문, 둘다 아닌지 판별하는 함수
* 
* @param s 판별할 문자열 참조
* @return int 0 회문, 1 유사회문, 2 둘 다 아님
*/
int isPalindrome(string_view s)
{
    // 투 포인터
    auto left = s.begin(), right = s.end() - 1;
    
    while (left < right)
    {
        if (*left != *right)
        {
            // 부분 문자열 회문 판독 람다 함수
            auto checkSubPalindrome = [](string_view str, auto l, auto r) {
                while (l < r)
                {
                    if (*l != *r)
                        return false;
                    ++l;
                    --r;
                }
                return true;
            };

            // 각각의 문자 하나를 제거하여 회문을 이루는지 판별
            return checkSubPalindrome(s, left + 1, right) || checkSubPalindrome(s, left, right - 1) ? 1 : 2;
        }
        ++left;
        --right;
    }

    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        cout << isPalindrome(s) << "\n";
    }


    return 0;
}
