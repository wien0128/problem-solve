#include <iostream>
#include <string>

using namespace std;

// 백준 1439 Greedy


int getMinFlip(const string& s)
{
    // 이전 문자와 다른 경우의 cnt 값들
    int cnt0{ 0 }, cnt1{ 0 };

    if (s.empty()) return 0;    // empty
    s[0] == '0' ? ++cnt0 : ++cnt1;  // init

    for (size_t i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i - 1])
        {
            s[i] == '0' ? ++cnt0 : ++cnt1;
        }
    }

    return min(cnt0, cnt1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    cout << getMinFlip(s);


    return 0;
}
