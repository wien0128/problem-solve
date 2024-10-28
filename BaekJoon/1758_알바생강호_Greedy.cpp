#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 알바생강호 1758 Greedy
// O( N log N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> tips(n);
    for (int& t : tips) cin >> t;

    // 내림차순 정렬
    // 팁 많이 주는 사람부터 그리디하게 받기
    sort(tips.rbegin(), tips.rend());

    long long totalTip{ 0 };
    for (int i = 0; i < n; ++i)
    {
        // 팁이 음수일 경우 0
        totalTip += max(0, tips[i] - i);
    }

    cout << totalTip;


    return 0;
}
