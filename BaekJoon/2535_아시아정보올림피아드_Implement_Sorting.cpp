#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 아시아정보올림피아드 2535 Impelment, Sorting
// O( n log n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // {score, country, id}
    // score 기준 내림차순 정렬을 위해 맨 앞에 배치
    vector<tuple<int, int, int>> ps(n);

    for (auto& [score, country, id] : ps)
    {
        cin >> country >> id >> score;
    }

    // score 기준 내림차순
    sort(ps.rbegin(), ps.rend());

    vector<pair<int, int>> winners; // {country, id}
    int countryCnt[101] = {};       // 국가별 수상자 수

    for (const auto& [score, country, id] : ps)
    {
        // 금, 은, 동 모두 수여했다면 종료
        if (winners.size() == 3) break;
        // 한 국가에서 최대 2명까지만 수상 가능
        if (countryCnt[country] < 2)
        {
            winners.emplace_back(country, id);
            ++countryCnt[country];
        }
    }

    for (const auto& [country, id] : winners)
    {
        cout << country << " " << id << "\n";
    }


    return 0;
}
