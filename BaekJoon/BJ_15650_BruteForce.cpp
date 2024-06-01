#include <iostream>
#include <vector>

using namespace std;

// BJ 15650 Brute-Force BackTracking


void dfs(int n, int m, vector<int>& seq, vector<bool>& used, int cnt)
{
    if (seq.size() == m)
    {
        for (int num : seq)
        {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = cnt; i <= n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            seq.push_back(i);

            dfs(n, m, seq, used, i + 1);

            used[i] = false;
            seq.pop_back();
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<int> seq;
    vector<bool> used(n + 1, false);

    dfs(n, m, seq, used, 1);


    return 0;
}