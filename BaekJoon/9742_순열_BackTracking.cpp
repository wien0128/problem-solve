#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 순열 9742 BackTracking
// O( n * n! )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    int n;

    while (cin >> str >> n)
    {
        int cnt{ 1 };   // 현재 순열 번호
        bool found{ false };    // n 번째 순열 여부
        string prevStr{ str };  // 원본 str

        // 오름차순
        sort(str.begin(), str.end());

        // 모든 순열 탐색
        do
        {
            // n 번째 순열을 찾았다면
            if (cnt == n)
            {
                found = true;
                cout << prevStr << " " << n << " = " << str << "\n";
                break;
            }
            ++cnt;
        } while (next_permutation(str.begin(), str.end()));

        // n 번째 순열이 없다면
        if (!found)
        {
            cout << str << " " << n << " = No permutation\n";
        }
    }
    

    return 0;
}
