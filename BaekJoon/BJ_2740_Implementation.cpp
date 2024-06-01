#include <iostream>
#include <vector>

using namespace std;

// 백준 2740 implementation
// DaC인줄 알았는데..?


// 행렬 곱
vector<vector<int>> matrixMultiple(vector<vector<int>>& A, vector<vector<int>>& B)
{
    //  A 행 크기           B 행 크기           B 열 크기
    int n{ (int)A.size() }, m{ (int)B.size() }, k{ (int)B[0].size() };

    // 행렬 곱의 결과 = n * k 크기 행렬 
    vector<vector<int>> res(n, vector<int>(k, 0));

    // O(N^3)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int p = 0; p < m; p++)
            {
                res[i][j] += A[i][p] * B[p][j];
            }
        }
    }

    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> A[i][j];
        }
    }

    int k;
    cin >> m >> k;

    vector<vector<int>> B(m, vector<int>(k, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> res{ matrixMultiple(A, B) };
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
