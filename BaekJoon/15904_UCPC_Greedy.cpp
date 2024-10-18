#include <iostream>
#include <string>

using namespace std;

// UCPC 15904 Greedy
// O( N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    getline(std::cin, str);

    const string ucpc = "UCPC";
    auto it = ucpc.begin();

    for (char c : str)
    {
        // 현재 문자가 UCPC의 현재 문자와 같은 경우
        if (c == *it) ++it;
        // UCPC를 모두 찾았다면 빠져 나옴
        if (it == ucpc.end()) break;
    }

    cout << (it == ucpc.end() ? "I love UCPC" : "I hate UCPC");


    return 0;
}
