#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// BJ 13305 Greedy
// 간단한 그리디 문제


// 기름값 그리디
ll getFuelCost(const vector<int>& distances, const vector<int>& prices)
{
    ll totalCost{ 0 };          // 총 비용
    ll minPrice{ prices[0] };   // 현재까지의 최소 기름값

    for (size_t i = 0; i < distances.size(); ++i)
    {
        // 현재 도시의 기름값이 이전 도시의 기름값 보다 싼가?
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        // 최소 기름값으로 다음 도시까지의 비용 계산
        totalCost += minPrice * distances[i];
    }

    return totalCost;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;                       // 도시 수

    vector<int> distances(n - 1);   // 도시 간 거리
    vector<int> prices(n);          // 도시별 기름값

    for (int i = 0; i < n - 1; i++)
    {
        cin >> distances[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    cout << getFuelCost(distances, prices);

    return 0;
}
