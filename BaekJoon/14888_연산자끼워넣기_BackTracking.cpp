#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// 연산자끼워넣기 14888 BackTracking
// O( (N - 1)! )


int n;
vector<int> nums;   // 수열 벡터
vector<int> ops(4); // 각 연산자 개수 벡터
int minValue = numeric_limits<int>::max();  // 최소값
int maxValue = numeric_limits<int>::min();  // 최대값

// op 에 대한 연산 수행 후 반환
inline int operations(int x, int y, int op)
{
    if (op == 0) return x + y;
    if (op == 1) return x - y;
    if (op == 2) return x * y;
    return x / y;
}

void dfs(int idx, int curRes)
{
    // 모든 숫자를 썼다면
    if (idx == n)
    {
        minValue = min(minValue, curRes);
        maxValue = max(maxValue, curRes);
        return;
    }

    // 모든 연산자 탐색
    for (int i = 0; i < 4; ++i)
    {
        // 연산자가 있다면
        if (ops[i] > 0)
        {
            --ops[i];
            dfs(idx + 1, operations(curRes, nums[idx], i));
            ++ops[i]; // 백트래킹
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    nums.resize(n);

    for (int& num : nums) cin >> num;
    for (int& op : ops) cin >> op;

    dfs(1, nums[0]);

    cout << maxValue << "\n" << minValue;
    

    return 0;
}
