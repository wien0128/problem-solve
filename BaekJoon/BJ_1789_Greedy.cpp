#include <iostream>

using namespace std;
using ll = long long;   // 1 <= S <= 42억

// 백준 1789 Greedy


ll getMaximumN(ll s)
{
    ll sum{ 0 }, idx{ 0 };
    while (true)
    {
        idx++;
        sum += idx;
        if (sum > s) break;
    }

    return idx - 1; // 마지막 항은 제외
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll s;
    cin >> s;

    cout << getMaximumN(s);


    return 0;
}
