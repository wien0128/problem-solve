#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 소가길을건너간이유3 14469 Greedy
// 간단한 그리디 문제
// O( n log n )


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // (도착시간, 검문시간)
    vector<pair<int, int>> cows(n);
    for (auto& c : cows)
    {
        cin >> c.first >> c.second;
    }

    // 도착 시간 기준 오름차순 정렬
    sort(cows.begin(), cows.end());

    // 이전 검문이 끝난 시각
    int curTime{ 0 };
    for (const auto& c : cows)
    {
        // 현재 시간과 도착 시간 중 더 늦은 시간부터
        // 그리디하게 검문 시작
        curTime = max(curTime, c.first) + c.second;
    }

    cout << curTime;


    return 0;
}
