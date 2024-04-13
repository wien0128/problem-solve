#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 백준 9251 LCS
// dp[i][j] = dp[i - 1][j - 1] + 1;
// dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])


int LCS(const string& str1, const string& str2)
{
    int len1 = str1.size();
    int len2 = str2.size();

    // dp[0][0] = 0, 
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            // 비교하는 값이 같다면 LCS + 1
            // 다르다면 왼쪽 혹은 위쪽 중 큰값
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[len1][len2];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    cout << LCS(str1, str2);


    return 0;
}
