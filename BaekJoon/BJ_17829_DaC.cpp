#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// BJ 17829 Divide-and-Conquer
// 나름 할만 한 분할 정복 문제


// 2x2 풀링 분할 정복
int pooling(vector<vector<int>>& matrix, int size)
{
    // 행렬 크기가 1x1이면 반환
    if (size == 1) return matrix[0][0];

    // 새 행렬은 현재 행렬의 절반 크기
    int newSize = size / 2;
    vector<vector<int>> newMatrix(newSize, vector<int>(newSize));

    for (int i = 0; i < size; i += 2)
    {
        for (int j = 0; j < size; j += 2)
        {
            // 각 2x2 행렬에서 두 번째로 큰 수를 찾아 새 행렬에 할당
            vector<int> pool = { 
                matrix[i][j], matrix[i][j + 1], 
                matrix[i + 1][j], matrix[i + 1][j + 1] 
            };
            // 오름차순 정렬
            sort(pool.begin(), pool.end());
            // 두 번째로 큰 수 할당
            newMatrix[i / 2][j / 2] = pool[2];
        }
    }
    // 1x1 행렬까지 재귀 반복
    return pooling(newMatrix, newSize);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // NxN 행렬
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    cout << pooling(matrix, n);


    return 0;
}
