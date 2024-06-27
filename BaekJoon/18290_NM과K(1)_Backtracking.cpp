#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// NM과K(1) 18290 BruteForce, Backtraking
// 역시 어렵다...

using Matrix = vector<vector<int>>;
using Visited = vector<vector<bool>>;

constexpr pair<int, int> directions[4] = {
    {-1, 0},    // 상
    {1, 0},     // 하
    {0, -1},    // 좌
    {0, 1}      // 우
};

// 현재 탐색하는 칸 유효성 검사
bool isValid(int i, int j, int n, int m, const Visited& visited)
{
    // 이전에 방문했다면 리턴 false
    if (visited[i][j]) return false;
    // [i, j] 기준 상하좌우 유효성 검사
    for (const auto& [dr, dc] : directions)
    {
        int ni = i + dr;
        int nj = j + dc;
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && visited[ni][nj])
        {
            return false;
        }
    }
    return true;
}

// Matrix 탐색
void dfs(int idx, int n, int m, int k, int curSum, int selected, 
            const Matrix& matrix, Visited& visited, int& maxSum)
{
    // k개만큼 골랐으면 최대값 업데이트
    if (selected == k)
    {
        maxSum = max(maxSum, curSum);
        return;
    }
    if (idx >= n * m) return; // 배열 끝까지 탐색했을 경우 종료

    int i = idx / m;    // 행
    int j = idx % m;    // 열

    if (isValid(i, j, n, m, visited))
    {
        visited[i][j] = true;   // 현재 칸 방문 표시
        dfs(idx + 1, n, m, k, curSum + matrix[i][j], selected + 1, matrix, visited, maxSum);
        visited[i][j] = false;  // 현재 칸 방문 표시 되돌림
    }
    // 다음 칸 이동
    dfs(idx + 1, n, m, k, curSum, selected, matrix, visited, maxSum);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    Visited visited(n, vector<bool>(m, false));
    Matrix matrix(n, vector<int>(m));  // 0-based indexing, n * m
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    int maxSum{ INT_MIN };  // 음수랑 비교해야될 수도 있음
    dfs(0, n, m, k, 0, 0, matrix, visited, maxSum);

    cout << maxSum;


    return 0;
}
