#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 덩치 7568 BruteForce
// O( n^2 )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // {몸무게, 키} 벡터
    vector<pair<int, int>> v(n);

    // 입력
    for (auto& [w, h] : v)
    {
        cin >> w >> h;
    }

    // 각 사람마다 모든 사람과 비교하여 순위 계산
    for (int i = 0; i < n; ++i)
    {
        // 초기 등수는 1
        int rank = 1;
        for (int j = 0; j < n; ++j)
        {
            // 자기 자신과의 비교가 아니라면
            if (i != j)
            {
                // 몸무게와 키 모두 더 크다면
                if (v[j].first > v[i].first && v[j].second > v[i].second)
                {
                    // ++등수
                    ++rank;
                }
            }
        }
        // 출력
        cout << rank << ' ';
    }

    
    return 0;
}
