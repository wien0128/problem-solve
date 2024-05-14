#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>   // C++20~

using namespace std;

// 백준 1026 Greedy
// 조건 쌩까고 B 재배열해도 풀림...

int getArrMinimum(vector<int>& A, vector<int>& B, int n)
{
    int sum{ 0 };

    for (int i = 0; i < n; i++)
    {
        //  += A의 가장 작은 값 * B의 가장 큰 값
        sum += A[i] * B[i];
    }

    return sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> A(n, 0);
    for (auto& val : A)
    {
        cin >> val;
    }
    sort(A.begin(), A.end());   // 오름차순

    vector<int> B(n, 0);
    for (auto& val : B)
    {
        cin >> val;
    }
    ranges::sort(B, greater());    // 내림차순

    cout << getArrMinimum(A, B, n);


    return 0;
}
