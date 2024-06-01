#include <iostream>

using namespace std;

// BJ 1476 brute-force
// e, s, m이 나올 때까지 year 때려 박기
// CRT도 가능


int calculateYear(int e, int s, int m)
{
    int year{ 1 };
    int earth{ 1 }, sun{ 1 }, moon{ 1 };

    while (1)
    {
        if (earth == e && sun == s && moon == m)
            return year;

        year++;
        earth = (earth % 15) + 1;
        sun = (sun % 28) + 1;
        moon = (moon % 19) + 1;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int e, s, m;

    cin >> e >> s >> m;

    cout << calculateYear(e, s, m) << '\n';


    return 0;
}