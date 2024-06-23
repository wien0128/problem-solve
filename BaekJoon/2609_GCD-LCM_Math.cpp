#include <iostream>

using namespace std;

// GCD_LCM 2609 Math
// 유클리드 호제법을 이용한 최대공약수, 최소공배수 구하기
// C++17 std::gcd()도 물론 있다.
// __gcd()는 GCC 컴파일 전용이니 지양하자.


// 최대공약수
constexpr int gcd(int a, int b)
{
    // GCD(a, b) = GCD(b, a % b)
    // a % b == 0, GCD(a, b) = b
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

// 최소공배수
constexpr int lcm(int a, int b, int gcdVal)
{
    // LCM = (a * b) / gcdVal
    return (a / gcdVal) * b;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int gcdVal = gcd(a, b);

    cout << gcdVal << "\n";
    cout << lcm(a, b, gcdVal) << "\n";
    

    return 0;
}
