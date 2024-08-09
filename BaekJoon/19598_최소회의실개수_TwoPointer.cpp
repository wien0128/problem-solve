#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최소회의실개수 19598 TwoPointer
// O( N logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // 회의 시작 시간, 종료 시간 벡터
    vector<int> sT(n), eT(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> sT[i] >> eT[i];
    }

    // 오름차순 정렬
    sort(sT.begin(), sT.end());
    sort(eT.begin(), eT.end());

    int minRooms{ 0 };  // 필요한 최소 회의실 개수
    int curRooms{ 0 };  // 현재 사용 중인 회의실 개수
    int l{ 0 }, r{ 0 }; // 투 포인터

    while (l < n)
    {
        // 새로운 회의를 시작해야한다면
        if (sT[l] < eT[r])
        {
            // 회의실 수 증가
            ++curRooms;
            ++l;
        }
        else
        {
            // 회의가 종료되었으니 회의실 수 감소
            --curRooms;
            ++r;
        }
        minRooms = max(minRooms, curRooms);
    }

    cout << minRooms;


    return 0;
}
