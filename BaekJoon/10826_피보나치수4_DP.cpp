#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 피보나치수4 10826 DP
// 피보나치지만 큰 수를 곁들인
// O( N^2 )


string add(const string& num1, const string& num2)
{
    string res;
    int c{ 0 }, sum{ 0 };   // 올림값, 자리별 덧셈 결과
    int len1 = num1.size(), len2 = num2.size();
    // 자리수를 위한 긴 길이 예약
    int maxLen = max(len1, len2);
    res.reserve(maxLen + 1);

    // 자리수 하나씩 더하기
    for (int i = 0; i < maxLen; ++i)
    {
        sum = c;    // 이전 자리 올림값 저장
        // num1의 자리수 더하기, 문자 -> 정수
        if (i < len1) sum += num1[len1 - i - 1] - '0';
        // num2의 자리수 더하기, 문자 -> 정수
        if (i < len2) sum += num2[len2 - i - 1] - '0';

        // 현재 자리의 수 저장
        res.push_back((sum % 10) + '0');
        // 올림값 계산
        c = sum / 10;
    }
    // 올림값이 남았다면 추가
    if (c) res.push_back(c + '0');

    // 계산 결과 뒤집기
    std::reverse(res.begin(), res.end());

    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 0, 1 처리
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    else if (n == 1)
    {
        cout << 1;
        return 0;
    }

    vector<string> dp(n + 1);
    dp[0] = "0";
    dp[1] = "1";

    for (int i = 2; i <= n; ++i)
    {
        // dp[i] = dp[i - 1] + dp[i - 2]
        dp[i] = add(dp[i - 1], dp[i - 2]);
    }

    cout << dp[n];


    return 0;
}
