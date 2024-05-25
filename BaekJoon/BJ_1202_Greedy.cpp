#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

// 백준 1202 Greedy
// 용량이 작은 가방부터 최선으로 채워나가면
// 최선의 결과를 얻을 수 있는 문제


struct Jewel {
    int weight;
    int value;
};

bool cmp(const Jewel& a, const Jewel& b)
{
    return a.weight < b.weight;
}

ll getMaxJewelryValue(vector<Jewel>& jewels, vector<int>& bags)
{
    ranges::sort(jewels, cmp);  // 무게 기준 오름차순
    ranges::sort(bags);         // 용량 기준 오름차순

    priority_queue<int> pq;     // 가치 기준 최대 힙
    ll totalValue{ 0 };         // 모든 가방에 넣은 총 보석 가치
    size_t index{ 0 };          // 보석 인덱스

    for (const auto& bag : bags)
    {
        // 가방에 넣을 수 있는 모든 보석들을 push
        while (index < jewels.size() && jewels[index].weight <= bag)
        {
            pq.push(jewels[index++].value);
        }
        if (!pq.empty())
        {
            totalValue += pq.top();     // 가장 비싼 보석 더하기
            pq.pop();           
        }
    }

    return totalValue;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Jewel> jewels(n);
    vector<int> bags(k);

    for (int i = 0; i < n; ++i)
    {
        cin >> jewels[i].weight >> jewels[i].value;
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> bags[i];
    }

    cout << getMaxJewelryValue(jewels, bags);

    
    return 0;
}
