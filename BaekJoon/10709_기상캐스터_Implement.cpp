#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 기상캐스터 10709 Implement
// O( h * w )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, w;
    cin >> h >> w;

    for (int i = 0; i < h; ++i)
    {
        string row;
        cin >> row;

        // 현재 지역에 구름이 오는데 걸리는 시간
        int time{ -1 };
        // 한 행씩 처리
        for (int j = 0; j < w; ++j)
        {
            if (row[j] == 'c')
            {
                time = 0;   // 구름 있는 지역은 시간 0
            } 
            else if (time != -1)
            {
                ++time;     // 구름 이후 지역은 시간 증가
            }
            cout << time << " ";
        }
        cout << "\n";
    }


    return 0;
}
