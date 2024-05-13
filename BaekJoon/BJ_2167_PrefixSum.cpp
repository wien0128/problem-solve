#include <iostream>
#include <vector>

using namespace std;
using matrix = vector<vector<int>>;

// 백준 2167 Prefix Sum
// 2차원 배열 누적합 공식만 알면 쉬운 문제


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    matrix nums(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> nums[i][j];
            // 누적 합 바로 계산
            // 위의 합 + 왼쪽의 합 - 두 번 더해진 대각선의 합
            // PS[i][j] = arr[i][j] + PS[i - 1][j] + PS[i][j - 1] - PS[i - 1][j - 1]
            nums[i][j] += nums[i][j - 1]
                + nums[i - 1][j]
                - nums[i - 1][j - 1];
        }
    }

    int k;
    cin >> k;
    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << nums[x2][y2]
            - nums[x2][y1 - 1]
            - nums[x1 - 1][y2]
            + nums[x1 - 1][y1 - 1]
            << "\n";
    }

    return 0;
}
