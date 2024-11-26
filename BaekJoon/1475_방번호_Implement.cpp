#include <iostream>
#include <array>
#include <string>

using namespace std;


// 방번호 1475 Implement
// O( n.length() )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    // 숫자 빈도 배열
    array<int, 10> cnt{};
    for (char d : str)
    {
        // 각 숫자의 빈도를 계산
        ++cnt[d - '0'];
    }

    // 6과 9는 서로 대체 가능하므로, 2로 나눈 올림값 계산
    cnt[6] = (cnt[6] + cnt[9] + 1) / 2;
    cnt[9] = cnt[6];

    // 가장 많이 필요한 숫자가 곧 필요한 세트의 수
    cout << *max_element(cnt.begin(), cnt.end());


    return 0;
}
