#include <iostream>
#include <string>

using namespace std;

// 백준 11723 BitMasking
// 대표적인 집합 문제


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, x, S{ 0 };
    cin >> m;

    string op;
    for (int i = 0; i < m; i++)
    {
        cin >> op;
        if (op == "add")
        {
            cin >> x;
            // x 번쨰 비트만 1
            S |= (1 << (x - 1));
        }
        else if (op == "remove")
        {
            cin >> x;
            // x 번쨰 비트만 0
            S &= ~(1 << (x - 1));
        }
        else if (op == "check") 
        {
            cin >> x;
            // x 번쨰 비트가 1 == x가 존재한다
            if (S & (1 << (x - 1))) cout << "1\n";
            else cout << "0\n";
        }
        else if (op == "toggle")
        {
            cin >> x;
            // XOR 활용, x 번째 비트 토글
            S ^= (1 << (x - 1));
        }
        else if (op == "all") 
        {
            // 전체 비트 1
            S = (1 << 20) - 1;
        }
        else if (op == "empty") 
        {
            // 전체 비트 0
            S = 0;
        }
    }


    return 0;
}
