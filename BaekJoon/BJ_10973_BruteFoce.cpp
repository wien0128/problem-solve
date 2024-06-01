#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// BJ 10973 Math BruteFoce
// 마찬가지로 prev_permutation 있음.


bool isPrev(vector<int>& v)
{
    int n = v.size();
    int i = n - 1;
    int j = n - 1;

    while (i > 0 && v[i - 1] <= v[i])
    {
        i--;
    }

    if (i == 0)
    {
        return false;
    }

    while (v[j] >= v[i - 1])
    {
        j--;
    }

    swap(v[j], v[i - 1]);
    reverse(v.begin() + i, v.end());
    

    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    /*
    do
    {
        for (auto& iter : v)
        {
            cout << iter << " ";
        }
        cout << '\n';
    } while (prev_permutation(v.begin(), v.end()));
    */

    if (isPrev(v))
    {
        for (auto& it : v)
        {
            cout << it << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << -1;
    }


    return 0;
}
