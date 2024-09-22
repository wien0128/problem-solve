#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 종이자르기 2628 Sorting
// 방향에 유의하자
// O( N logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 넓이, 높이, 커팅횟수
    int w, h, n;
    cin >> w >> h >> n;

    // 가로 방향(세로 커팅) 좌표 벡터, 상단과 하단 경계 추가
    vector<int> hor{ 0, h };
    // 세로 방향(가로 커팅) 좌표 벡터, 좌측과 우측 경계 추가
    vector<int> ver{ 0, w };

    while (n--)
    {
        int dir, pos;
        cin >> dir >> pos;
        (dir == 0 ? hor : ver).push_back(pos);
    }

    // 좌표 오름차순 정렬
    sort(hor.begin(), hor.end());
    sort(ver.begin(), ver.end());

    // 최대 가로, 세로 간격
    int maxH{ 0 }, maxW{ 0 };
    
    // 잘린 좌표 사이 가장 큰 간격 탐색
    for (int i = 1; i < hor.size(); ++i)
        maxH = max(maxH, hor[i] - hor[i - 1]);
    for (int i = 1; i < ver.size(); ++i)
        maxW = max(maxW, ver[i] - ver[i - 1]);

    // 최대 간격의 곱이 답
    cout << maxH * maxW;


    return 0;
}
