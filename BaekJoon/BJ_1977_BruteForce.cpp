#include <iostream>
#include <cmath>

using namespace std;

// 백준 1977 BruteForce


int getPerfectSquare(int m, int n, int& minValue)
{
    int sum{ 0 };
    minValue = -1;
    // 루트 m부터 완전 제곱수 찾기
    // 반올림(루트(M)
    for (int i = ceil(sqrt(m)); i * i <= n; ++i)
    {
        int squr = i * i;
        sum += squr;    // 완전제곱수 합계
        if (minValue == -1) minValue = squr; // 첫 번째 완전제곱수가 최소값
    }

    return sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    int minValue;
    int sum = getPerfectSquare(m, n, minValue);

    (minValue == -1) ? cout << "-1" : cout << sum << '\n' << minValue;
    
    return 0;
}
