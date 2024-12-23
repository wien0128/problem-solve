#include <iostream>
#include <string>

using namespace std;

// 좋은단어 3986 Implementation
// O( n * m )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int cnt{ 0 };   // 좋은 단어 개수

    while (n--)
    {
        string word, tmp;
        cin >> word;

        for (char ch : word)
        {
            // tmp의 마지막 문자와 현재 문자가 같으면 짝을 이룸 -> 부분 좋은 단어
            // 다르다면, 새로운 문자 추가
            if (!tmp.empty() && tmp.back() == ch)
            {
                tmp.pop_back();
            }
            else
            {
                tmp.push_back(ch);
            }
        }

        // tmp가 비어있다면 모든 문자가 짝을 이룸 -> 좋은 단어
        if (tmp.empty()) ++cnt;
    }

    cout << cnt;


    return 0;
}
