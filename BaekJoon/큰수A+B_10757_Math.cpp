#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 큰수A+B 10757 Math
// python 제외 브론즈5 수준의 문제는 아닌 듯?
// O( max(a.size(), b.size()) )


string add(const string& a, const string& b)
{
    string res;
    // 올림, 각 자리의 합계
    int c{ 0 }, sum{ 0 };
    // a, b 일의 자리 포인터
    int i = a.size() - 1, j = b.size() - 1;

    // 두 숫자 더한 후에도 올림수까지 처리
    while (i >= 0 || j >= 0 || c)
    {
        // 이전 연산의 올림수 더하기
        sum = c;
        // 현재 자리수 숫자로 변환 후 더하기
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        // 현재 자리의 합을 문자 형태로 추가
        res += (sum % 10) + '0';
        // 올림수 계산
        c = sum / 10;
    }

    // 일의 자리 -> 가장 큰 자리로 계산했기에
    // 뒤집어야 올바른 값
    reverse(res.begin(), res.end());

    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << add(a, b);


    return 0;
}
