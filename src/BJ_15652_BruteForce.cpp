#include <iostream>
#include <vector>

using namespace std;

// BJ 15652 Brute-Force BackTracking


void dfs(int n, int m, vector<int>& seq, int prev)
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

    for (int i = prev; i <= n; i++)
    {
        seq.push_back(i);
        dfs(n, m, seq, i);
        seq.pop_back();
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

    dfs(n, m, seq, 1);


    return 0;
}