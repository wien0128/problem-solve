#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N과_M(8) 15657 Brute Force
// 백트래킹 기본 문제
// 비내림차순: A_1 <= A_2 <= ... <= A_k-1 <= A_k


// DFS를 이용한 중복 허용 수열 생성 (비내림차순)
void dfs(const vector<int>& nums, vector<int>& seq, int m, int depth, int index)
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

    // index부터 모든 숫자에 대해 반복
    for (int i = index; i < nums.size(); ++i)
    {
        // 현재 숫자 수열에 추가
        // 수열의 마지막 숫자 덮어 쓰기 (백트래킹)
        seq[depth] = nums[i];
        // 다음 depth 재귀 호출 (i를 넘김으로 i번째 이하의 숫자는 선택 X)
        dfs(nums, seq, m, depth + 1, i);
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

    dfs(nums, seq, m, 0, 0);


    return 0;
}
