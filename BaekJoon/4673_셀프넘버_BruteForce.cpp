#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

constexpr int MAX{ 10000 };

// 셀프넘버 4673 BruteFroce, Math
// O( n log n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 생성자 기록용 배열
    // true 라면 생성자가 존재 = 셀프넘버가 아님
    array<bool, MAX + 1> arr{};

    // O(n)
    for (register int i = 1; i <= MAX; ++i)
    {
        int n = i, dn = i;
        
        // d(n) 계산 O(log n)
        while (n)
        {
            dn += n % 10;
            n /= 10;
        }

        // 10'000 보다 작을 경우만 기록
        if (dn <= MAX) arr[dn] = true;
    }

    // 셀프넘버 출력
    for (register int i = 1; i <= MAX; ++i)
    {
        if (!arr[i]) cout << i << '\n';
    }


    return 0;
}
