#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2559 누적합


int getPrefixSum(vector<int>& temperatures, int n, int k)
{
    // 전체 누적합 계산
    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + temperatures[i - 1];
    }

    // 길이 k에 대한 모든 구간 합 계산, 최대값 찾기
    // 1번째 0 ~ k 구간 초기화
    int maxSum = prefixSum[k] - prefixSum[0];
    for (int i = 1; i <= n - k; i++)
    {
        int curSum = prefixSum[i + k] - prefixSum[i];
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

    cout << getPrefixSum(temperatures, n, k) << '\n';


    return 0;
}
