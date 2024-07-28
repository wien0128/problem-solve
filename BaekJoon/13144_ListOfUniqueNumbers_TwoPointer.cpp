#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ListOfUniqueNumbers 13144 TwoPointer
// 연속한 n 개 이상의 수를 뽑는 경우의 수 = n(n + 1) / 2
// O( n )


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

    unordered_map<int, int> freq;   // 숫자 i의 출현 횟수
    int l{ 0 };                     // 투 포인터
    long res{ 0 };                  // 모든 연속 부분 배열의 길이 합

    for (int r = 0; r < n; ++r)
    {
        ++freq[arr[r]]; // 현재 숫자 출현 횟수 증가

        // 현재 숫자가 두 번 이상 출현했다면
        while (freq[arr[r]] > 1)
        {
            --freq[arr[l]];
            ++l;
        }

        // 윈도우 사이의 모든 부분 배열의 길이 추가
        res += (r - l + 1);
    }

    cout << res;


    return 0;
}
