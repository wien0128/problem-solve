#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// BJ 2309 brute-force


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> dwarves(9);
    int sum{ 0 };

    for (int i = 0; i < 9; i++)
    {
        cin >> dwarves[i];
        sum += dwarves[i];
    }

    sort(dwarves.begin(), dwarves.end());

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - (dwarves[i] + dwarves[j]) == 100)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k != i && k != j)
                    {
                        cout << dwarves[k] << '\n';
                    }
                }
                return 0;
            }
        }
    }


    return 0;
}