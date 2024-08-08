#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 강의실 1374 Greedy
// O( N logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> lectures;
    for (int i = 0; i < n; ++i)
    {
        int id, start, end;
        cin >> id >> start >> end;
        lectures.push_back({ start, 1 });
        lectures.push_back({ end, -1 });
    }

    // 시간 기준 오름차순 정렬
    sort(lectures.begin(), lectures.end());

    int curRooms{ 0 };  // 현재 사용중인 강의실의 수
    int maxRooms{ 0 };  // 최대로 사용한 강의실의 수
    for (const auto& l : lectures)
    {
        curRooms += l.second;
        maxRooms = max(maxRooms, curRooms);
    }

    cout << maxRooms;


    return 0;
}
