#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 화살표그리기 15970 BruteForce
// O( n log m )


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // (색깔, 좌표[])
    map<int, vector<int>> points;
    int pos, color;
    for (int i = 0; i < n; ++i)
    {
        cin >> pos >> color;
        points[color].push_back(pos);
    }

    // 모든 점에서 시작하는 화살표들의 길이 합
    int res{ 0 };

    for (auto& [color, pos] : points)
    {
        // 각 색상 좌표들 오름차순 정렬
        sort(pos.begin(), pos.end());
        // 각 색상 좌표 벡터 크기
        int size = pos.size();

        // 조건: 2 < n, IndexOutOfBoundsException 은 안 터짐
        // 0 번째 - 1 번째 점 거리 계산
        res += pos[1] - pos[0];
        // 1번째 - (m - 1) 번째 사이 모든 점의 최소 거리 계산
        for (int i = 1; i < size - 1; ++i)
        {
            res += min(pos[i] - pos[i - 1], pos[i + 1] - pos[i]);
        }
        // m 번째 - (m - 1) 번째 점 거리 계산
        res += pos[size - 1] - pos[size - 2];
    }

    cout << res;


    return 0;
}
