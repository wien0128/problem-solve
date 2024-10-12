#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 암기왕 2776 Sorting
// O( (n + m) log n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n;

        vector<int> note1(n);
        for (int& num : note1)
        {
            cin >> num;
        }

        sort(note1.begin(), note1.end());

        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            int q;
            cin >> q;

            // note1에 q가 존재하면 1, 없으면 0 출력
            cout << (binary_search(note1.begin(), note1.end(), q) ? 1 : 0) << "\n";
        }
    }


    return 0;
}
