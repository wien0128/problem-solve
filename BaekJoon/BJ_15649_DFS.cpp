#include <iostream>
#include <vector>

using namespace std;


void dfs(int n, int m, vector<int>& seq, vector<bool>& used)
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
        if (!used[i])
        {
            used[i] = true;
            seq.push_back(i);


            dfs(n, m, seq, used);

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

    dfs(n, m, seq, used);

    return 0;
}