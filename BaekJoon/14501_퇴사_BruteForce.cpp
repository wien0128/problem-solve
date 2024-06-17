#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 퇴사 14501 Brute Force
// 브루트포스 버전, 성능은 별로다.


int getMaximizePay(const vector<pair<int, int>>& tp, int n, int day, int curProfit)
{
    // n + 1일 이후
    if (day >= n) return curProfit;

    // 현재 day에서 일을 안하고 건너뛰는 경우
    int notWork = getMaximizePay(tp, n, day + 1, curProfit);

    // 현재 day에서 일을 할 수 있고 하는 경우
    int work{ 0 };
    if (day + tp[day].first <= n)
    {
        work = getMaximizePay(tp, n, day + tp[day].first, curProfit + tp[day].second);
    }

    return max(notWork, work);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> tp(n);   // { Ti(기간), Pi(보수) }

    for (int i = 0; i < n; ++i)
    {
        cin >> tp[i].first >> tp[i].second;
    }

    cout << getMaximizePay(tp, n, 0, 0);


    return 0;
}
