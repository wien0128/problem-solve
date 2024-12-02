#include <iostream>
#include <string>

using namespace std;

// 3의배수 1769 Implement, Math
// O( n log n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string num;
    cin >> num;

    int res{ 0 };

    // 한 자리수가 될 때까지 반복
    while (num.size() > 1)
    {
        // 현재 숫자의 자리수 합
        int sum = 0;
        
        // 각 자릿수 합산
        for (char n : num)
        {
            // 문자 -> 정수
            sum += n - '0';
        }
        // 자리수 합 -> 문자열
        num = to_string(sum);
        // 변환 횟수 증가
        ++res;
    }

    // 변환 횟수, 한 자리수 3의 배수 여부
    cout << res << "\n" << ((num[0] - '0') % 3 == 0 ? "YES" : "NO");


    return 0;
}
