#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

// 로또 6603 Math, Bitmasking
// O( kC6 * k )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true)
    {
        int k;
        cin >> k;

        if (k == 0) break;

        vector<int> s(k);
        for (auto& e : s)
        {
            cin >> e;
        }

        // 조합 생성 비트마스크
        vector<bool> mask(k, false);
        // 처음 6개는 true, 나머지는 false
        fill_n(mask.begin(), 6, true);

        do
        {
            // iota -> [ 0, k - 1 ] 범위 인덱스 생성
            // filter -> mask가 true인 인덱스만 선택
            // 선택된 인덱스의 s 의 원소만 출력
            for (auto i : views::iota(0, k) | views::filter([&](int i) { return mask[i]; }))
            {
                cout << s[i] << " ";
            }
            cout << "\n";
        } while (prev_permutation(mask.begin(), mask.end()));

        cout << "\n";
    }


    return 0;
}
