#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 짐챙기는숌 1817 Greedy
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if (n <= 0)
    {
        cout << 0;
        return 0;
    }

    // 필요한 박스 개수, 현재 박스에 담긴 무게
    int boxCnt{ 1 }, curWeight{ 0 };
    while (n--)
    {
        int w;
        cin >> w;

        // 박스에 담을 수 있다면 넣고,
        // 아니라면 새 박스 사용
        if (curWeight + w > m)
        {
            ++boxCnt;
            curWeight = 0;
        }
        curWeight += w;
    }

    cout << boxCnt;


    return 0;
}
