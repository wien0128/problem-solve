#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N과_M(7) 15656 Brute Force
// 백트래킹 기본 문제
// 어렵다..


// DFS를 이용한 중복 허용 수열 생성
void dfs(const vector<int>& nums, vector<int>& seq, int n, int m, int depth)
{
    // 수열의 길이가 m이 되면 출력
    if (m == depth)
    {
        for (const int& n : seq)
        {
            cout << n << " ";
        }
        cout << "\n";
        return;
    }

    // 모든 숫자에 대해 반복
    for (int i = 0; i < n; ++i)
    {
        // 현재 숫자 수열에 추가
        // 수열의 마지막 숫자 덮어 쓰기 (백트래킹)
        seq[depth] = nums[i];
        // 다음 depth 재귀 호출
        dfs(nums, seq, n, m, depth + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end()); // 오름차순

    vector<int> seq(m);

    dfs(nums, seq, n, m, 0);


    return 0;
}
