#include <iostream>
#include <vector>

using namespace std;

// CD 4158 TwoPointer, Set, BinarySearch
// 다양한 방법이 존재하는 문제
// O( n + m )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true)
    {
        int n, m;
        cin >> n >> m;

        // base case
        if (n == 0 && m == 0) break;

        vector<int> cd1(n), cd2(m);
        for (int& x : cd1) cin >> x;
        for (int& x : cd2) cin >> x;

        // 투 포인터와 중복되는 CD 카운트
        int i{ 0 }, j{ 0 }, cnt{ 0 };
        
        // 투 포인터 중복 탐색
        while (i < n && j < m)
        {
            // 두 CD가 겹친다면
            if (cd1[i] == cd2[j])
            {
                ++cnt;      // 중복 카운트 증가
                ++i; ++j;   // 투 포인터 모두 이동
            }
            // 번호가 작은 CD를 가리키는 포인터 이동
            else if (cd1[i] < cd2[j])
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }

        cout << cnt << "\n";
    }


    return 0;
}
