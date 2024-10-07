#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 수열 2491 DP
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int& e : v)
    {
        cin >> e;
    }

    // 최대 수열 길이, 연속 증가 수열 길이, 연속 감소 수열 길이
    int maxLen{ 1 }, incLen{ 1 }, decLen{ 1 };
    for (int i = 1; i < n; ++i)
    {
        // 연속으로 증가/감소하는 수열이면 길이 + 1, 아니면 1
        incLen = (v[i] >= v[i - 1]) ? incLen + 1 : 1;
        decLen = (v[i] <= v[i - 1]) ? decLen + 1 : 1;
        maxLen = max({ maxLen, incLen, decLen });
    }
    
    cout << maxLen;


    return 0;
}
