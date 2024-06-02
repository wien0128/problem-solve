#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using Field = vector<vector<int>>;

// 백준 1012 DFS
// 그룹 세기 문제, 아직은 구현이 어렵다


// 방향 벡터
const vector<pair<int, int>> directions = {
    {0, -1},    // 상
    {0, 1},     // 하
    {-1, 0},    // 좌
    {1, 0}      // 우
};

class Farm {
private:
    int m, n;       // m * n
    Field field;    // 밭

    // 탐색 범위 검사 + 배추 존재 여부 검사
    bool isValid(int x, int y) const
    {
        return x >= 0 && x < m && y >= 0 && y < n && field[y][x] == 1;
    }

    // DFS
    void DFS(int x, int y)
    {
        stack<pair<int, int>> s;
        s.push({ x, y });
        field[y][x] = 0;    // 현재 좌표 방문 처리

        while (!s.empty())
        {
            auto [cx, cy] = s.top();    // 현재 좌표
            s.pop();

            // 현재 좌표 기준 상하좌우 탐색
            for (const auto& [dx, dy] : directions)
            {
                int nx = cx + dx;
                int ny = cy + dy;

                // 탐색 범위 초과 시 재낌
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                // 배추 발견 시 push
                if (field[ny][nx] == 1)
                {
                    s.push({ nx, ny });
                    field[ny][nx] = 0;  // 방문 처리
                }
            }
        }
    }
public:
    Farm(int m, int n) : m(m), n(n), field(n, vector<int>(m, 0)) {}

    // 배추 추가
    void addCabbage(int x, int y)
    {
        field[y][x] = 1;
    }

    // 배추 군집 카운팅
    int cntGroups()
    {
        int cnt{ 0 };   // 배추 군집 수
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < m; ++x)
            {
                if (field[y][x] == 1)
                {
                    DFS(x, y);
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        // 밭의 가로, 밭의 세로, 배추의 개수
        int m, n, k;
        cin >> m >> n >> k;

        Farm farm(m, n);

        for (int i = 0; i < k; ++i)
        {
            int x, y;
            cin >> x >> y;
            farm.addCabbage(x, y);
        }

        cout << farm.cntGroups() << "\n";
    }


    return 0;
}
