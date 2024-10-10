#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 수열정렬 1015 Sorting
// O( N log N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // {값, 인덱스}
    vector<pair<int, int>> arr(n);
    // 결과 벡터
    vector<int> res(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first;    // 값
        arr[i].second = i;      // 인덱스
    }

    // 값 기준 정렬, 같다면 원래 인덱스 기준 정렬
    sort(arr.begin(), arr.end());

    // B[P[i]] = A[i]
    for (int i = 0; i < n; ++i)
    {
        res[arr[i].second] = i;
    }

    for (int e : res)
    {
        cout << e << " ";
    }


    return 0;
}
