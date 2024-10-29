#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2+1세일 11508 Greedy
// O( N log N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cost(n);
    for (int& c : cost) cin >> c;

    // 가격 기준 내림차순 정렬
    sort(cost.rbegin(), cost.rend());

    long long totalCost{ 0 };
    for (int i = 0; i < n; ++i)
    {
        // 3번째 상품은 무료
        if (i % 3 != 2)
        {
            totalCost += cost[i];
        }
    }

    cout << totalCost;


    return 0;
}
