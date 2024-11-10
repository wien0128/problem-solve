#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

// 빈도정렬 2910 Sorting
// O( n log n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, c;
    cin >> n >> c;

    unordered_map<int, int> freq;   // 각 숫자의 빈도 맵
    vector<pii> nums;              // {숫자, 등장 인덱스} 벡터
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        // 처음 등장한 숫자라면 받기
        // 아니라면, 빈도만 증가
        if (freq[x]++ == 0)
        {
            nums.emplace_back(x, i);
        }
    }

    sort(nums.begin(), nums.end(), [&](const pii& a, const pii& b) {
        // 두 숫자의 빈도가 다르다면
        if (freq[a.first] != freq[b.first])
        {
            // 빈도 기준 내림차순
            return freq[a.first] > freq[b.first];
        }
        // 같다면, 등장 인덱스 기준 오름차순
        return a.second < b.second;
        });

    // 정렬된 벡터 출력
    for (const auto& [x, _] : nums)
    {
        for (int i = 0; i < freq[x]; ++i)
        {
            cout << x << ' ';
        }
    }


    return 0;
}
