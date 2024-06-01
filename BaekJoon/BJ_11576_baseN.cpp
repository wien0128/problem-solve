#include <iostream>
#include <vector>
#include <cmath>

// 백준 11576 진법 간 변환

using namespace std;


// A진법 -> 10진법
int toDecimal(int baseA, vector<int>& digitA, int size)
{
    int decimal{ 0 };
    for (int i = 0; i < size; i++)
    {
        decimal += digitA[i] * pow(baseA, size - i - 1);
    }

    return decimal;
}

// 10진법 -> B진법
void toBaseB(int decimal, int baseB)
{
    vector<int> digitB;

    while (decimal > 0)
    {
        digitB.push_back(decimal % baseB);
        decimal /= baseB;
    }

    for (int i = digitB.size() - 1; i >= 0; i--)
    {
        cout << digitB[i] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int baseA, baseB, m;

    cin >> baseA >> baseB >> m;

    vector<int> digitA(m);
    for (int i = 0; i < m; i++)
    {
        cin >> digitA[i];
    }

    int decimal = toDecimal(baseA, digitA, m);

    toBaseB(decimal, baseB);


    return 0;
}
