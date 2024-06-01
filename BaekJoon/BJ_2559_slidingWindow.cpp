#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2559 누적합
// Sliding Window 활용


int slidingWindow(vector<int>& temperatures, int n, int k)
{
    // 처음 k까지의 값 계산
    int curSum{ 0 };
    for (int i = 0; i < k; i++)
    {
        curSum += temperatures[i];
    }

    int maxSum = curSum;

    // Sliding Window 이동시키면 k구간만큼 계산
    for (int i = k; i < n; i++)
    {
        curSum += temperatures[i] - temperatures[i - k];
        maxSum = max(maxSum, curSum);
    }

    return maxSum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> temperatures(n);
    for (int i = 0; i < n; i++)
    {
        cin >> temperatures[i];
    }

    cout << slidingWindow(temperatures, n, k) << '\n';


    return 0;
}
