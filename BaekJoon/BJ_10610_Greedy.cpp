#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 백준 10610 Greedy

//   30의 배수 조건
// 1. 0이 포함되어 있는가? 
//  = 10의 배수 가능성
// 2. 각 자리의 합이 3의 배수인가? 
//  = 자리를 바꿔도 여전히 3의 배수


// 30의 배수 반환
string getMultipleOfTThirty(string n)
{
    int sum{ 0 };
    bool hasZero{ false };

    for (char c : n)
    {
        sum += c - '0'; // 각 자리 수 합계
        if (c == '0')
        {
            hasZero = true;
        }
    }

    // 0이 없거나 3의 배수가 아니면 -1
    if (!hasZero || sum % 3 != 0) return "-1";

    // 내림차순 정렬로 가장 큰 수 만듦
    ranges::sort(n, greater<char>());

    return n;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string n;
    cin >> n;

    cout << getMultipleOfTThirty(n);


    return 0;
}
