#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 게으른백곰 10025 SlidingWindow


constexpr int MAX_POS{ 1'000'001 };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    // 얼음 벡터, ices[좌표] = 얼음
    vector<int> ices(MAX_POS, 0);
    for (int i = 0; i < n; ++i)
    {
        int g, x;
        cin >> g >> x;
        ices[x] = g;
    }

    // 슬라이딩 윈도우 크기, ( k + 중심 + k )
    int windowSize = 2 * k + 1;
    // 현재 윈도우 내의 얼음 개수 최대 얼음 개수
    int curSum{ 0 }, maxSum{ 0 };

    // 0 ~ windowSize - 1까지 
    for (int i = 0; i < windowSize && i < MAX_POS; ++i)
    {
        curSum += ices[i];
    }
    maxSum = curSum;

    // windowSize ~ MAX_POS까지
    // 오른쪽으로 이동하며 왼쪽 값 제외
    for (int i = windowSize; i < MAX_POS; ++i)
    {
        curSum += ices[i] - ices[i - windowSize];
        maxSum = max(curSum, maxSum);
    }

    cout << maxSum;


    return 0;
}
