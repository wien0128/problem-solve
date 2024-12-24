#include <iostream>
#include <unordered_map>

using namespace std;

// 반복수열 2331 Implementation
// O( 10^d * d * p ), d = n의 자릿수, p = 거듭제곱의 횟수


// 자릿수의 p 제곱의 합 계산
int func(int n, int p)
{
    int sum{ 0 };
    while (n > 0)
    {
        int digit = n % 10;     // 자릿수
        int power = 1;          // 제곱수
        for (int i = 0; i < p; ++i)
        {
            power *= digit;     // p 제곱 계산
        }
        sum += power;
        n /= 10;                // 다음 자릿수
    }

    return sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, p;
    cin >> a >> p;

    unordered_map<int, int> idxMap; // 숫자가 등장하는 인덱스 맵
    int curInt{ a };                // 현재 숫자
    int idx{ 0 };                   // 현재 인덱스

    while (true)
    {
        if (idxMap.count(curInt))   // 현재 숫자가 이미 등장했다면
        {
            // 반복수열 시작점의 인덱스 출력
            // 시작점 이전의 숫자들의 개수가 문제의 정답
            cout << idxMap[curInt];
            break;
        }
        idxMap[curInt] = idx++;     // 현재 숫자의 인덱스 저장
        curInt = func(curInt, p);   // 현재 숫자 업데이트
    }


    return 0;
}
