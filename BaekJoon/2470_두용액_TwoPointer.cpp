#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 두용액 2470 TwoPointer
// 0에 가장 가까운 두 수의 합을 찾는 문제


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> solutions(n);
    for (int& s : solutions)
    {
        cin >> s;
    }

    // 오름차순
    sort(solutions.begin(), solutions.end());

    // 투 포인터
    int l{ 0 }, r{ n - 1 };
    // 두 용액의 합이 가장 0에 가까운 용액들
    int sl{ solutions[l] }, sr{ solutions[r] };
    // 두 용액의 합들 중 0에 가장 가까운 값
    int colestSum = abs(solutions[l] + solutions[r]);

    while (l < r)
    {
        int curSum = solutions[l] + solutions[r];

        // 현재 합의 절대값이 더 가까운 경우 갱신
        if (abs(curSum) < colestSum)
        {
            colestSum = abs(curSum);
            sl = solutions[l];
            sr = solutions[r];
        }

        // 현재 합이 0인 경우 답을 찾았기에 종료
        if (curSum == 0) 
            break;

        // 현재 합이 0보다 작으면 l 포인터 오른쪽 이동
        if (curSum < 0)
        {
            ++l;
        }
        // 현재 합이 0보다 크면 r 포인터 왼쪽 이동
        else
        {
            --r;
        }
    }

    cout << sl << " " << sr;


    return 0;
}
