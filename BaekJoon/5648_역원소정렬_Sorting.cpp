#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

// 역원소정렬 5648 Sorting
// O( nm + n log n ), m is s length


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> nums(n);
    for (ll& num : nums)
    {
        string s;
        cin >> s;
        // 숫자 문자열 뒤집기
        reverse(s.begin(), s.end());
        // string -> long long
        // 가장 큰 자리수가 0일 경우 자동으로 제거
        num = stoll(s);
    }

    // 오름차순 정렬
    sort(nums.begin(), nums.end());

    for (const ll& num : nums)
    {
        cout << num << "\n";
    }


    return 0;
}
