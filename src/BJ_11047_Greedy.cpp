#include <iostream>
#include <vector>

using namespace std;

// BJ 11047 Greedy


int greedyCoins(int amount, const vector<int>& coins)
{
    int n = coins.size();
    int cnt{ 0 };

    for (int i = n - 1; i >= 0; i--)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            cnt++;
        }
    }

    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, amount, res{ 0 };

    cin >> n >> amount;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // Soultion 1:
    cout << greedyCoins(amount, coins) << '\n';

    // Soultion 2:
    for (int i = n - 1; i >= 0; i--)
    {
        res += amount / coins[i];
        amount %= coins[i];
    }

    cout << res;
    

    return 0;
}
