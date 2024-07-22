#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 두용액 2470 BinarySearch
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

    // 0에 가장 가까운 두 용액의 합
    int minSum{ abs(solutions[0] + solutions[1]) };
    int s1{ solutions[0] }, s2{ solutions[1] };

    for (int i = 0; i < n - 1; ++i)
    {
        int l = solutions[i];
        int target = -l;    // 두 번째 용액 목표값
        // target보다 크거나 같은 첫 번째 요소 찾기
        auto it = lower_bound(solutions.begin() + i + 1, solutions.end(), target);

        // 이전 요소와의 합 비교
        if (it != solutions.begin() + i + 1)
        {
            int prev = *(it - 1);   // 목표 값 바로 이전의 용액
            int sum = l + prev;

            if (abs(sum) < minSum)
            {
                minSum = abs(sum);
                s1 = l;
                s2 = prev;
            }
        }

        // 현재 요소와의 합 비교
        if (it != solutions.end())
        {
            int curr = *it;     // 목표 값에 가장 가까운 용액
            int sum = l + curr;

            if (abs(sum) < minSum)
            {
                minSum = abs(sum);
                s1 = l;
                s2 = curr;
            }
        }
    }

    cout << s1 << " " << s2;


    return 0;
}
