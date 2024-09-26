#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

// 국영수 10825 Sorting
// O( N log N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // [국어, 영어, 수학, 이름]
    vector<tuple<int, int, int, string>> v(n);
    for (auto& [k, e, m, name] : v)
    {
        cin >> name >> k >> e >> m;
    }

    // 1. 국어점수 기준 내림차순
    // 2. 영어점수 기준 오름차순
    // 3. 수학점수 기준 내림차순
    // 4. 이름 기준 사전순
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return tie(get<0>(b), get<1>(a), get<2>(b), get<3>(a))
            < tie(get<0>(a), get<1>(b), get<2>(a), get<3>(b));
        });

    for (const auto& [k, e, m, name] : v)
    {
        cout << name << "\n";
    }


    return 0;
}
