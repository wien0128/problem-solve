#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 임시반장정하기 1268 Implement
// O( n^2 )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 학생들의 5학년까지의 반 정보 행렬 벡터
    vector<vector<int>> v(n, vector<int>(5));
    for (auto& s : v)
    {
        for (auto& g : s)
        {
            cin >> g;
        }
    }

    // 반장 학생 번호 (0-based), 최대 같은 반 횟수
    int res{ 0 }, maxCnt{ 0 };

    // 각 학생 기준 다른 학생과 비교
    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;
        // 현재 학생과 다른 모든 학생 비교
        for (int j = 0; j < n; ++j)
        {
            // 자기 자신 제외
            if (i == j) continue;
            // 5학년 동안 같은 반 여부 확인
            for (int k = 0; k < 5; ++k)
            {
                if (v[i][k] == v[j][k])
                {
                    ++cnt;  // 같은 반이었으면 증가
                    break;  
                }
            }
        }

        // 최대 횟수와 임시 반장 갱신
        if (cnt > maxCnt)
        {
            maxCnt = cnt;
            res = i;
        }
    }

    cout << res + 1;


    return 0;
}
