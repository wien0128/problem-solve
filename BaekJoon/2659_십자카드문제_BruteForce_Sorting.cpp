#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// 십자카드문제 2659 BruteForce, Sorting
// O((target - 1111 + 1) log (target - 1111 + 1))
// = O( n log n )


// 시계수 계산 메소드
inline int getMinRotation(int a, int b, int c, int d)
{
    int num1 = a * 1000 + b * 100 + c * 10 + d;
    int num2 = b * 1000 + c * 100 + d * 10 + a;
    int num3 = c * 1000 + d * 100 + a * 10 + b;
    int num4 = d * 1000 + a * 100 + b * 10 + c;

    return min({ num1, num2, num3, num4 });
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // 입력된 수의 시계수 계산 후 타겟팅
    int target = getMinRotation(a, b, c, d);
    // 시계수 저장 set
    set<int> res;

    // 1111 ~ target까지의 모든 시계수 계산
    // target 보다 큰 수는 회전 시켜도 큼
    for (register int num = 1111; num <= target; ++num)
    {
        int i = num / 1000;         // 천의 자리
        int j = (num / 100) % 10;   // 백의 자리
        int k = (num / 10) % 10;    // 십의 자리
        int l = (num % 10);         // 일의 자리

        // 숫자에 0이 포함될 경우 건너뜀
        if (i == 0 || j == 0 || k == 0 || l == 0)
            continue;

        // 자동 중복 방지와 오름차순 정렬
        res.insert(getMinRotation(i, j, k, l));
    }

    // target의 인덱스 출력
    cout << distance(res.begin(), res.find(target)) + 1;


    return 0;
}
