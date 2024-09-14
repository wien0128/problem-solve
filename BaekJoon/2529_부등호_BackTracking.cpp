#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 부등호 2529 BackTracking
// 0~9 순열을 조건에 맞게 탐색하는 문제
// O( 10! )


int k;
char signs[10];     // 부등호 배열
bool isUsed[10];    // 숫자 중복 선택 방지 배열
string minNum = "9876543210", maxNum = "0";

// 부등호 조건 검사 메서드
bool isValid(char a, char b, char sign)
{
    return (sign == '<') ? (a < b) : (a > b);
}

// 백트래킹
void DFS(string num, int depth)
{
    // 부등호에 맞는 모든 숫자를 선택했다면
    if (depth == k + 1)
    {
        // 최소값, 최대값 갱신
        minNum = min(minNum, num);
        maxNum = max(maxNum, num);
        return;
    }

    // 0~9까지 중 하나 선택
    for (int i = 0; i <= 9; ++i)
    {
        // 중복되지 않는 숫자이며, 부등호를 만족하는 경우
        if (!isUsed[i] && (depth == 0 || isValid(num.back(), i + '0', signs[depth - 1])))
        {
            isUsed[i] = true;
            DFS(num + to_string(i), depth + 1);
            isUsed[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> k;
    for (int i = 0; i < k; ++i) cin >> signs[i];

    DFS("", 0);

    cout << maxNum << "\n" << minNum;

    
    return 0;
}
