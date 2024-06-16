#include <iostream>
#include <vector>

using namespace std;

// 1로_만들기2 12852 DP
// 점화식:
// dp[i] = min( dp[i-1], dp[i/2](if i%2==0), dp[i/3](if i%3==0)) + 1


pair<int, vector<int>> minOperation(int n)
{
    vector<int> dp(n + 1);      // i -> 1 최소 연산 횟수
    vector<int> path(n + 1);    // i -> 1 경로

    for (int i = 2; i <= n; ++i)
    {
        // i -1
        dp[i] = dp[i - 1] + 1;
        path[i] = i - 1;
        
        // 2로 나눠 떨어지고 최소값이라면
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] + 1;
            path[i] = i / 2;
        }
        // 3으로 나눠 떨어지며 최소값이라면
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] + 1;
            path[i] = i / 3;
        }
    }

    vector<int> res;
    for (int i = n; i != 0; i = path[i])
    {
        res.push_back(i);
    }

    return { dp[n], res };
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 최소 연산 횟수, 경로
    const auto& [min, path] = minOperation(n);

    cout << min << "\n";
    for (const auto& x : path)
    {
        cout << x << " ";
    }
    cout << "\n";


    return 0;
}
