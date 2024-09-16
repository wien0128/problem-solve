#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 점수계산 2822 Sorting
// O( 5 log5 + 3 ) = O(1)


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // {점수, 번호}
    vector<pair<int, int>> scores(8);
    for (int i = 0; i < 8; ++i)
    {
        int x;
        cin >> x;
        scores[i] = { x, i + 1 };   // 번호는 1-based indexing
    }

    // 상위 5개만 오름차순 부분 정렬
    partial_sort(scores.begin(), scores.begin() + 5, scores.end(),
        [](const auto& a, const auto& b) {return a.first > b.first; });

    int sum{ 0 };       // 총합계
    vector<int> idx(5); // 상위 5개 인덱스

    for (int i = 0; i < 5; ++i)
    {
        sum += scores[i].first;
        idx[i] = scores[i].second;
    }

    sort(idx.begin(), idx.end());

    cout << sum << "\n";
    for (int i : idx) cout << i << " ";

    
    return 0;
}
