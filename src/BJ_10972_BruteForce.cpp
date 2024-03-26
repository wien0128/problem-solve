#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// BJ 10972 Math BruteFoce
// next_permutation이라는게 있었네...


bool isNext(vector<int>& v)
{
    int n = v.size();
    int i = n - 1;
    int j = n - 1;

    while (i > 0 && v[i - 1] >= v[i])
    {
        i--;
    }

    if (i <= 0)
    {
        return false;
    }

    while (v[j] <= v[i - 1])
    {
        j--;
    }
    
    swap(v[i - 1], v[j]);
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
    } while (next_permutation(v.begin(), v.end()));
    */

    if (isNext(v))
    {
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << -1;
    }


    return 0;
}
