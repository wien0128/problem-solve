#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 로봇프로젝트 3649 TwoPointer
// 주어진 레고 조각들 중 두 조각의
// 합이 x 와 같은지 판별하는 문제


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

        int l{ 0 }, r{ n - 1 }; // 투 포인터
        int sum{ 0 };

        while (l < r)
        {
            // 두 레고 조각의 합
            sum = legos[l] + legos[r];

            if (sum < x) ++l;
            else if (sum > x) --r;
            else break;
        }

        // 구멍을 막을 수 있다면
        if (sum == x)
        {
            cout << "yes " << legos[l] << " " << legos[r] << "\n";
        }
        else
        {
            cout << "danger\n";
        }
    }


    return 0;
}
