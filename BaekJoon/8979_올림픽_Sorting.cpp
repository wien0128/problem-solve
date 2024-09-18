#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 올림픽 8979 Sorting
// O( N logN )


// 나라별 메달 구조체
struct Country
{
    int id, gold, silver, bronze;
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, k;
    cin >> n >> k;

    vector<Country> v(n);

    for (auto& e : v)
    {
        cin >> e.id >> e.gold >> e.silver >> e.bronze;
    }

    // 금 > 은 > 동 메달 수 기준 내림차순 정렬
    sort(v.begin(), v.end(), [](const Country& a, const Country& b) {
        if (a.gold != b.gold) return a.gold > b.gold;
        if (a.silver != b.silver) return a.silver > b.silver;
        return a.bronze > b.bronze;
        });


    int rank{ 1 };  // 현재 국가의 순위
    for (int i = 0; i < n; ++i)
    {
        // 현재 국가가 이전 국가와 메달 수가 다르다면 갱신
        // 메달 수가 같은 국가들의 순위를 동일하게 유지하기 위함
        if (i > 0 && (v[i].gold != v[i - 1].gold ||
                      v[i].silver != v[i - 1].silver ||
                      v[i].bronze != v[i - 1].bronze))
        {
            rank = i + 1;
        }

        if (v[i].id == k)
        {
            cout << rank;
            break;
        }
    }

    
    return 0;
}
