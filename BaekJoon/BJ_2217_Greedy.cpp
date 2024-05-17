#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2217 Greedy
// 문제 이해를 잘못해서 헷갈렸던 문제


// 최대 중량 계산
int getMaxWeight(vector<int>& ropes, int n)
{
    ranges::sort(ropes);   // 로프 내림차순

    int maxWeight{ 0 };
    for (int i = 0; i < n; i++)
    {
        // 현재 로프의 최대 중량 = (해당 로프의 중량 * N)
        maxWeight = max(maxWeight, ropes[i] * (n - i));
    }

    return maxWeight;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> ropes(n);
    for (auto& it : ropes)
    {
        cin >> it;
    }

    cout << getMaxWeight(ropes, n);


    return 0;
}
