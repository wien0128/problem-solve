#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 리모컨 1107 Brute Force
// 1. +, - 버튼만으로 채널 n으로 이동하는 방법
// 2. 0~9 버튼과 +, -버튼으로 채널 n으로 이동하는 방법
// 구현이 까다로운 문제


// 채널 num이 고장난 버튼 포함 여부 판별 함수
bool isBroken(int num, const vector<bool>& broken)
{
    // 0번 버튼 확인
    if (num == 0) return broken[0];
    // 각 자릿수 버튼 고장 여부 확인
    // 하나라도 고장난 버튼이라면 true
    while (num > 0)
    {
        if (broken[num % 10]) return true;
        num /= 10;
    }

    return false;
}

// 채널 num의 자릿수 계산 함수
int countDigits(int num)
{
    if (num == 0) return 1;
    
    // 자릿수 계산
    int cnt{ 0 };
    while (num > 0)
    {
        cnt++;
        num /= 10;
    }

    return cnt;
}

int leastMoveToN(int n, const vector<bool>& broken)
{
    // 채널 n까지 +, -만으로 이동하는 경우
    // 절대값(n - 100)
    int minMoves{ abs(n - 100) };

    // n ±500,000 내의 모든 채널 검사
    for (int i = max(0, n - 500000); i < min(1000000, n + 500000); ++i)
    {
        // i에 대해 broken된 버튼이 없다면
        if (!isBroken(i, broken))
        {
            // 채널 i 입력시 필요한 버튼 눌림
            int moves = countDigits(i) + abs(i - n);
            minMoves = min(minMoves, moves);
        }
    }

    return minMoves;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int m;
    cin >> m;
    
    vector<bool> broken(10, false);
    for (int i = 0; i < m; ++i)
    {
        int b;
        cin >> b;
        broken[b] = true;
    }

    cout << leastMoveToN(n, broken);

    return 0;
}
