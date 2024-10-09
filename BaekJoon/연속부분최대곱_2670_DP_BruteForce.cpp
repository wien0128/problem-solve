#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// 연속부분최대곱 2670 DP, BruteForce
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 최대곱, 현재곱
    double maxProduct, curProduct;
    cin >> maxProduct;
    curProduct = maxProduct;

    for (int i = 1; i < n; ++i)
    {
        double x;
        cin >> x;
        // 현재 곱 계산 후 갱신
        curProduct = max(x, curProduct * x);
        // 최대 곱 갱신
        maxProduct = max(maxProduct, curProduct);
    }

    // 소수점 3자리까지 출력
    cout << fixed << setprecision(3)<< maxProduct;


    return 0;
}
