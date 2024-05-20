#include <iostream>
#include <vector>
#include <string>

using namespace std;
using matrix = vector<vector<int>>;

// 백준 1080 Greedy
// TC가 좀 이상한 문제


// (x, y) 부터 3*3 행렬 뒤집기
void flip(matrix& m, int x, int y)
{
    for (int i = x; i < x + 3; ++i)
    {
        for (int j = y; j < y + 3; ++j)
        {
            m[i][j] = 1 - m[i][j];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    matrix a(n, vector<int>(m));
    matrix b(n, vector<int>(m));
    string line;

    // 띄어쓰기 없이 입력 받기에 변환 필요
    for (auto& row : a)
    {
        cin >> line;
        for (int i = 0; i < m; ++i)
        {
            row[i] = line[i] - '0';
        }
    }
    for (auto& row : b)
    {
        cin >> line;
        for (int i = 0; i < m; ++i)
        {
            row[i] = line[i] - '0';
        }
    }

    int flipCnt{ 0 };   // flip 횟수
    // n,m - 3 만큼 반복, flip이 n,m + 3 만큼 뒤집기 때문
    for (int i = 0; i <= n - 3; ++i)
    {
        for (int j = 0; j <= m - 3; ++j)
        {
            if (a[i][j] != b[i][j])
            {
                flip(a, i, j);
                ++flipCnt;
            }
        }
    }

    // 두 행렬이 같은가?
    if (a == b)
    {
        cout << flipCnt;
    }
    else
    {
        cout << -1;
    }
    

    return 0;
}
