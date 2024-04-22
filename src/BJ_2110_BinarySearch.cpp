#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// 백준 2110 Binary Search
// 거리를 기준으로 한다는 아이디어가 까다로웠던 문제


// mid 거리만큼 c개의 라우터가 설치 가능한가?
bool isValidRouter(vector<ll>& houses, ll mid, int c)
{
    // 첫 집은 무조건 설치 가정
    ll cnt{ 1 }, prevHouse{ houses[0] };
    for (int i = 1; i < houses.size(); i++)
    {
        // 현재 최대 거리 이상인가?
        if (houses[i] - prevHouse >= mid)
        {
            // 설치
            cnt++;
            prevHouse = houses[i];
        }
    }

    return cnt >= c;
}

// 이분 탐색, 집들 사이의 거리 기준
ll getMaxDistanceRouters(vector<ll>& houses, int c)
{
    // end = 끝 집 - 첫 집 = 최대 거리
    ll start{ 1 }, mid, end{ houses[houses.size() - 1] - houses[0] };
    ll res{ 0 };

    while (start <= end)
    {
        mid = (start + end + 1) / 2;

        // c개 이상 설치했는가?
        if (isValidRouter(houses, mid, c))
        {
            // 최대 거리 저장 
            res = max(res, mid);
            // 설치 거리를 늘림
            start = mid + 1;
        }
        else
        {
            // 아니라면, 설치 거리 줄임
            end = mid - 1;
        }
    }

    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    cin >> n >> c;

    vector<ll> houses(n);
    for (int i = 0; i < n; i++)
    {
        cin >> houses[i];
    }

    // 오름차순 정렬
    sort(houses.begin(), houses.end());

    cout << getMaxDistanceRouters(houses, c) << "\n";


    return 0;
}
