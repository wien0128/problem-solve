#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 배열합치기 11728 Two_Pointer
// 간단한 투 포인터 문제

/**
    두 배열 오름차순 정렬 후 출력
    @param n A배열 크기
    @param m B배열 크기
*/
void printSortedArr(vector<int>& A, vector<int>& B, int n, int m)
{
    int i{ 0 }, j{ 0 }; // 투 포인터
    while (i < n && j < m)
    {
        if (A[i] <= B[j])
        {
            cout << A[i++] << " ";
        }
        else
        {
            cout << B[j++] << " ";
        }
    }

    while (i < n)
    {
        cout << A[i++] << " ";
    }
    while (j < m)
    {
        cout << B[j++] << " ";
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (auto& i : A)
    {
        cin >> i;
    }
    vector<int> B(m);
    for (auto& i : B)
    {
        cin >> i;
    }

    // std::merge 풀이
    vector<int> res(n + m);
    merge(A.begin(), A.end(), B.begin(), B.end(), res.begin());

    for (auto& i : res)
    {
        cout << i << " ";
    }

    // 투 포인터 풀이
    printSortedArr(A, B, n, m);


    return 0;
}
