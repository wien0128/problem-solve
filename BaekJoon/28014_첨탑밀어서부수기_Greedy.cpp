#include <iostream>

using namespace std;

// 첨탑밀어서부수기 28014 Greedy
// O( N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int height, prevHeight; // 현재 높이, 이전 높이
    cin >> prevHeight;

    int cnt{ 1 };   // 민 횟수
    for (int i = 1; i < n; ++i)
    {
        cin >> height;
        // 현재 높이가 이전 높이 보다 크거나 같다면 밀어야 함
        if (height >= prevHeight)
        {
            ++cnt;
        }
        prevHeight = height;    // 이전 높이 갱신
    }

    cout << cnt;


    return 0;
}
