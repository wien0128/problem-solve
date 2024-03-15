#include <iostream>

// 백준 1748 Brute-Force

using namespace std;
using ll = long long;


ll calculateTotalDigits(int n)
{
    ll res{ 0 };

    for (int i = 1; i <= n; i *= 10)
    {
        res += n - i + 1;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    if (n < 10)
    {
        cout << n;
        return 0;
    }

    cout << calculateTotalDigits(n);


    return 0;
}
