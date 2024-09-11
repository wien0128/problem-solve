#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 양조장 11557 Sorting
// O( T * N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        // { 술 소비량, 대학교 }
        vector<pair<int, string>> v(n);

        for (auto& [d, u] : v)
        {
            cin >> u >> d;
        }

        auto maxDrunker = max_element(v.begin(), v.end());

        cout << maxDrunker->second << "\n";
    }


    return 0;
}
