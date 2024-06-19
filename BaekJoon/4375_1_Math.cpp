#include <iostream>

using namespace std;

// 1 4375 Math
// Mk = (Mk-1 * 10 + 1) % n


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    while (cin >> n) // != EOF
    {
        int num{ 1 }, res{ 1 };
        while (num % n != 0)
        {
            num = num * 10 + 1; // 1, 11, 111, 111, ...
            num %= n;
            ++res;              // 자릿수
        }

        cout << res << "\n";
    }
    

    return 0;
}
