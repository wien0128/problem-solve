#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 11399 Greedy

int getMinTime(vector<int>& P, int n)
{
    sort(P.begin(), P.end());

    int totalTime{ 0 }, waitingTime{ 0 };

    for (int i = 0; i < n; i++)
    {
        // += Pn이 인출하는데 기다리는 시간 더하기
        waitingTime += P[i];
        // 총 시간 += 기다린 시간
        totalTime += waitingTime;
    }

    return totalTime;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> P(n);
    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }

    cout << getMinTime(P, n);


    return 0;
}
