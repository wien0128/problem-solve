#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2000문제푼임스 25822 TwoPointer
// O( N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double c;
    int n;
    cin >> c >> n;

    vector<int> solved(n);
    for (int& s : solved)
    {
        cin >> s;
    }

    // 최대 스트릭 프리즈 개수 계산
    int maxFreezes{ min(2, static_cast<int>(c / 0.99)) };

    int l{ 0 }, r{ 0 };     // 투 포인터
    int freezeUsed{ 0 };    // 사용한 프리즈 사용 개수
    int maxStreak{ 0 };     // 최대 스트릭 유지 일수
    int curStreak{ 0 };     // 현재 스트릭 유지 일수
    
    while (r < n)
    {
        // i번째 날에 푼 문제가 있다면
        if (solved[r] > 0)
        {
            ++curStreak;
            ++r;
        }
        else
        {
            // 프리즈를 사용할 수 있다면
            if (freezeUsed < maxFreezes)
            {
                ++freezeUsed;
                ++curStreak;
                ++r;
            }
            // 프리즈를 사용할 수 없다면
            else
            {
                if (solved[l] == 0)
                {
                    --freezeUsed;
                }
                --curStreak;
                ++l;
            }
        }

        maxStreak = max(maxStreak, curStreak);
    }

    cout << maxStreak << "\n";
    cout << *max_element(solved.begin(), solved.end());


    return 0;
}
