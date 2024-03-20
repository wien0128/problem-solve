#include <iostream>
#include <vector>

using namespace std;

// BJ 15651 Brute-Force BackTracking


void dfs(int n, int m, vector<int>& seq, vector<int>& used)
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

    for (int i = 1; i <= n; i++)
    {
        if (used[i] < m)
        {
            ++used[i];
            seq.push_back(i);

            dfs(n, m, seq, used);

            --used[i];
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
    vector<int> used(n + 1, 0);

    dfs(n, m, seq, used);


    return 0;
}