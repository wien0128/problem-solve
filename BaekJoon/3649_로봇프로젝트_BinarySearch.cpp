#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 로봇프로젝트 3649 BinarySearch
// 주어진 레고 조각들 중 두 조각의
// 합이 x 와 같은지 판별하는 문제
// O( nlogn )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;

    while (cin >> x)
    {
        x *= 10'000'000; // cm -> nm

        int n;
        cin >> n;

        vector<int> legos(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> legos[i];
        }
        
        // 오름차순
        sort(legos.begin(), legos.end());

        bool found = false;

        for (int i = 0; i < n; ++i)
        {
            int target = x - legos[i];
            
            if (binary_search(legos.begin() + i + 1, legos.end(), target))
            {
                cout << "yes " << legos[i] << " " << target << "\n";
                found = true;
                break;
            }
        }

        if (!found) cout << "danger\n";
    }


    return 0;
}
