#include <iostream>
#include <vector>

using namespace std;

// 등수구하기 1205 Implementation
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, score, p;
    cin >> n >> score >> p;

    vector<int> v(n);
    for (int& e : v) cin >> e;

    // 현재 순위, 순위표 개수
    int pos{ 1 }, cnt{ 0 };
    for (int i = 0; i < n; ++i)
    {
        if (score < v[i]) ++pos;    // 더 높은 점수가 존재하면 순위 증가
        else if (score == v[i]) {}  // 같다면 
        else break;                 // 현재 점수가 더 크다면 루프 중단
        ++cnt;
    }
    
    if (cnt == p) pos = -1;         // 순위표 안의 모든 점수보다 작다면 -1
    if (n == 0) pos = 1;            // 순위표에 아무 점수도 없다면 1

    cout << pos;


    return 0;
}
