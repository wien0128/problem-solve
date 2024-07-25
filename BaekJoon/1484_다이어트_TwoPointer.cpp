#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

// 다이어트 1484 TwoPointer
// x^2 - y^2 = G 를 만족하는 모든 x 를 찾는 문제
// 전체 탐색 상한은 √G + 1 따라서 O(√G)


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int G;
    cin >> G;

    vector<int> res;
    int low{ 1 };
    int high{ 1 };

    // 두 제곱수의 차이가 G가 되는 모든 경우 탐색
    while (low < high || high == 1)
    {
        ll lowSquare = static_cast<ll>(low) * low;
        ll highSquare = static_cast<ll>(high) * high;
        ll diff = highSquare - lowSquare;   // 두 제곱수의 차이

        // 제곱수의 차이가 G와 같으면
        if (diff == G)
        {
            res.push_back(high);
        }

        // 제곱수의 차이가 G보다 크다면
        if (diff > G) {
            ++low;  // 제곱수 간의 차이 감소
        } else {
            ++high; // 제곱수 간의 차이 증가
        }
    }

    if (res.empty()) 
    {
        cout << -1;
    }
    else
    {
        for (const auto& r : res)
        {
            cout << r << "\n";
        }
    }


    return 0;
}
