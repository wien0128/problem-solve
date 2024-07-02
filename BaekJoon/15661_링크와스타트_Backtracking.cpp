#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;
using Matrix = vector<vector<int>>;
using Team = vector<int>;

// 링크와스타트 15661 Backtracking
// O(2^n)

/**
    가능한 모든 팀 조합을 탐색하여
    두 팀 간의 능력치 최소 차이값 계산

    @param n 플레이어 수
    @param S 능력치 값 2D 벡터
    @param index 현재 탐색 중인 플레이어 인덱스
    @param start 스타트팀 벡터
    @param link 링크팀 벡터
    @param minDiff 최소 능력치 차이값 변수
    @param startStat 스타트팀의 현재 능력치 합
    @param linkStat 링크팀의 현재 능력치 합
*/
void getMinDiff(int n, const Matrix& S, int index, Team& start, Team& link, 
    int& minDiff, int startStat, int linkStat)
{
    // 모든 팀원을 배정한 경우
    if (index == n)
    {
        // 각 팀에 한 명이라도 배정되었을 경우
        if (!start.empty() && !link.empty())
        {
            minDiff = min(minDiff, abs(startStat - linkStat));
        }
        return;
    }

    // 현재 index의 팀원을 Start팀에 추가하는 경우
    start.push_back(index);
    int newStartStat = startStat;
    for (int i : start)
    {
        newStartStat += S[i][index] + S[index][i];
    }
    getMinDiff(n, S, index + 1, start, link, minDiff, newStartStat, linkStat);
    start.pop_back();   // 백트래킹
    
    // 현재 index의 팀원을 Link팀에 추가하는 경우
    link.push_back(index);
    int newLinkStat = linkStat;
    for (int i : link)
    {
        newLinkStat += S[i][index] + S[index][i];
    }
    getMinDiff(n, S, index + 1, start, link, minDiff, startStat, newLinkStat);
    link.pop_back();    // 백트래킹
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // 능력치 벡터 n * n
    Matrix S(n, vector<int>(n, 0));
    int num;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> num;
            S[i][j] = num;
        }
    }

    int minDiff{ numeric_limits<int>::max() };
    Team start, link;

    getMinDiff(n, S, 0, start, link, minDiff, 0, 0);

    cout << minDiff;


    return 0;
}
