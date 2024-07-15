#include <iostream>
#include <vector>

using namespace std;

// K보다큰구간 14246 TwoPointer

using ll = long long;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& a : arr)
    {
        cin >> a;
    }
    ll k;
    cin >> k;

    ll cnt{ 0 };       // k보다 큰 구간 합의 개수
    ll curSum{ 0 };    // 현재 구간 [i, j]의 합
    int j{ 0 };         // 투 포인터

    for (int i = 0; i < n; ++i)
    {
        // 오른쪽으로 이동하며 구간 합 계산
        while (j < n && curSum + arr[j] <= k)
        {
            curSum += arr[j];   // 현재 구간의 합에 arr[j] 더하기
            ++j;
        }

        // 현재 구간 [i, j]에서 k보다 큰 합을 가지는 구간의 수는 (n - j)개
        cnt += (n - j);

        // 다음 구간으로 넘어가기 전 현재 시작점 값 빼기
        curSum -= arr[i];
    }

    cout << cnt;


    return 0;
}
