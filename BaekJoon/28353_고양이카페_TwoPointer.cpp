#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 고양이카페 28353 TwoPointer
// 그리디하게 생각하면 쉽다
// O( NlogN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> cats(n);
    for (int& w : cats)
    {
        cin >> w;
    }

    sort(cats.begin(), cats.end());

    // 투 포인터
    int l{ 0 }, r{ n - 1 };
    // 무게 k를 넘지 않고 만족하는 사람 수
    int pairs{ 0 };

    while (l < r)
    {
        if (cats[l] + cats[r] <= k)
        {
            ++pairs;
            ++l;
            --r;
        }
        else
        {
            --r;
        }
    }

    cout << pairs;


    return 0;
}
