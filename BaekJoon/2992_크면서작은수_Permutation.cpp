#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 크면서작은수 2992 BackTracking
// 다음 순열을 찾으면 된다...
// O( N! )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string x;
    cin >> x;

    if (next_permutation(x.begin(), x.end()))
    {
        cout << x;
    }
    else
    {
        cout << "0";
    }
    

    return 0;
}
