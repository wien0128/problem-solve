#include <iostream>
#include <vector>

using namespace std;

// 부분수열의합 1182 BackTracking
// O( 2^N )


void BackTracking(int idx, int curSum, int& cnt, 
    const int& n, const int& s, const vector<int>& v)
{
    // 모든 요소를 검사했을 때
    if (idx == n)
    {
        // 합이 S 와 같은 부분수열이 있다면 cnt 증가
        if (curSum == s) ++cnt;
        return;
    }

    // 현재 원소를 포함하지 않는 경우
    BackTracking(idx + 1, curSum, cnt, n, s, v);

    // 현재 원소를 포함하는 경우
    BackTracking(idx + 1, curSum + v[idx], cnt, n, s, v);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, s;
    cin >> n >> s;

    vector<int> v(n);
    for (int& e : v)
    {
        cin >> e;
    }

    int cnt{ 0 };

    BackTracking(0, 0, cnt, n, s, v);

    // s 가 0인 경우 공집합은 제외
    if (s == 0) --cnt;

    cout << cnt;


    return 0;
}
