#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 카약과강풍 2891 Greedy, Implementation
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s, r;
    cin >> n >> s >> r;

    // 양쪽 끝 인덱스 참조 오류 방지 + 2
    // 1: 여분 있음
    // 0: 여분 없음
    // -1: 여분 필요, 손상된 카약 있음
    vector<int> teams(n + 2, 0);

    int teamIdx;
    // 카약이 손상된 팀
    for (int i = 0; i < s; ++i)
    {
        cin >> teamIdx;
        --teams[teamIdx];
    }
    // 카약 여분이 있는 팀
    for (int i = 0; i < r; ++i)
    {
        cin >> teamIdx;
        ++teams[teamIdx];
    }

    for (int i = 1; i <= n; ++i)
    {
        // 현재 팀 카약이 모자르다면
        if (teams[i] == -1)
        {
            // 이전(왼쪽) 팀에 여분이 있다면
            if (teams[i - 1] == 1)
            {
                ++teams[i];
                --teams[i - 1];
            }
            // 다음(오른쪽) 팀에 여분이 있다면
            else if (teams[i + 1] == 1)
            {
                ++teams[i];
                --teams[i + 1];
            }
        }
    }

    // 여분을 배분 후 여전히 출발 못하는 팀 개수 출력
    cout << count(teams.begin() + 1, teams.end(), -1);


    return 0;
}
