#include <iostream>

using namespace std;

// 수들의합5 2018 TwoPointer, Math
// start=1, end=5는 1+2+3+4+5 = 15 = n이라는 뜻


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    int start{ 1 }, end{ 1 };   // 투 포인터
    int sum{ 1 };               // 초기 합은 1
    int cnt{ 0 };               // 가능한 방법의 수
    
    // n / 2를 넘으면 더 이상 연속된 자연수로는 N을 못 만듦.
    while (start <= n / 2)
    {
        // 현재 합이 n보다 작다면
        // N에 도달하기 위해 더 많은 숫자가 필요
        if (sum < n)
        {
            ++end;  // 오른쪽 이동, 범위 확장
            sum += end;
        }
        // 현재 합이 n보다 크다면
        // N을 초과했기에 범위를 줄임
        else if (sum > n)
        {
            sum -= start;
            ++start;    // 오른쪽 이동, 범위 축소
        }
        // 현재 합이 n과 같다면
        // N에 도달하는 범위를 늘려 계속 탐색
        else
        {
            ++cnt;  // 가능한 방법을 찾음
            ++end;  // 오른쪽 이동, 범위 확장
            sum += end;
        }
    }

    // +1은 N도 포함
    cout << cnt + 1;
    
    
    // 등차수열의 합 공식 풀이
    // 2N = i * (2a + i - 1)
    int sum{ 0 }, cnt{ 0 };
    for (int i = 1; sum < n; ++i)
    {
        sum += i;
        // n을 i개의 연속된 자연수의 합으로 나타낼 수 있다면
        if ((n - sum) % i == 0) 
            ++cnt;
    }
    cout << cnt;


    return 0;
}
