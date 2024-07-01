#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;
using Matrix = vector<vector<int>>;
using Team = vector<int>;

// 스타트와링크 14889 Backtracking
// O(2n * n^2) = O(n^2)


/**
    팀 능력치 계산 O((n/2)^2) = (n^2 / 4) = (n^2)
    @return power 팁 조합 능력치
*/
int getTeamPower(const Team& team, const Matrix& S)
{
    int power{ 0 };
    int size = team.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            power += S[team[i]][team[j]] + S[team[j]][team[i]];
        }
    }
    return power;
}

/**
   모든 팀 조합을 순회하여 나누기
   @param index 현재 고를 팀원의 인덱스
   @return minDiff 최소차이값
*/
int divideTeams(int index, Team& start, Team& link,
    const Matrix& S, int n, int& minDiff)
{
    // n만큼 고르면 모든 팀원이 배정된 것
    if (index == n)
    {
        // 두 팀의 크기가 같은 경우에만 갱신
        if (start.size() == n / 2 && link.size() == n / 2)
        {
            int startPower{ getTeamPower(start, S) };
            int linkPower{ getTeamPower(link, S) };
            int diff{ abs(startPower - linkPower) };
            minDiff = min(minDiff, diff);
        }
        return minDiff;
    }

    // 차이가 없다면 반환
    if (minDiff == 0) return minDiff;

    // start 팀에 index를 추가할 경우
    if (start.size() < n / 2)
    {
        start.push_back(index);
        divideTeams(index + 1, start, link, S, n, minDiff);
        start.pop_back();   // 백트래킹
    }
    // link 팀에 index를 추가할 경우
    if (link.size() < n / 2)
    {
        link.push_back(index);
        divideTeams(index + 1, start, link, S, n, minDiff);
        link.pop_back();    // 백트래킹
    }

    return minDiff;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // 능력치 벡터 n * n
    Matrix S(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> S[i][j];
        }
    }

    Team start, link;
    // 능력치 차이 최소값
    int minDiff{ numeric_limits<int>::max() };
    
    cout << divideTeams(0, start, link, S, n, minDiff);


    return 0;
}
