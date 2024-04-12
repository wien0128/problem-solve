#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2565 LIS
// 전체 전깃줄 수 - 교차하지 않고 설치 가능한 전깃줄 수(LIS)
// = 교차를 일으키는 전깃줄의 수
// 지문만 보고는 떠올리기 힘든 꽤 트리키한 문제다. 

int removeCablesMin(vector<pair<int, int>> cables)
{
    vector<int> lis;

    // B 전봇대의 LIS 구하기
    for (const auto& val : cables)
    {
        auto it = lower_bound(lis.begin(), lis.end(), val.second);

        if (it == lis.end())
        {
            lis.push_back(val.second);
        }
        else
        {
            *it = val.second;
        }
    }

    // return 값은 교차를 일으키는 전깃줄 수
    return cables.size() - lis.size();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> cables;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cables.push_back(make_pair(a, b));
    }

    // A 전봇대 기준 정렬
    sort(cables.begin(), cables.end());

    cout << removeCablesMin(cables);


    return 0;
}
