#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 어두운굴다리 17266 Implementation, BinarySearch
// 조금만 시간을 들이면 이진 탐색이 구태여 필요 없다
// O( m )


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> pos(m);
    for (int& p : pos) cin >> p;

    // 1. 시작점-첫 가로등 사이 간격
    int maxGap{ pos[0] };

    // 2. 모든 가로등 사이의 최대 간격 계산
    for (int i = 1; i < m; ++i)
    {
        // 현재 가로등과 이전 가로등 간의 간격
        int tmp = pos[i] - pos[i - 1];
        // 모든 가로등은 동일한 높이, 범위를 가짐
        // 따라서 가로등 사이 중간 지점을 포함하도록 
        // ⌈tmp/2⌉ 로 계산
        maxGap = max(maxGap, (tmp + 1) / 2);
    }

    // 3. 마지막 가로등과 끝점 사이 간격
    maxGap = max(maxGap, n - pos[m - 1]);

    // 3가지 간격 중 가장 큰 값을 취하면 정답
    cout << maxGap;


    return 0;
}
