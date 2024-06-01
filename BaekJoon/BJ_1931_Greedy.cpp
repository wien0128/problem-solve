#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 1931 Greedy


struct Meeting {
    int strat;
    int end;
};

// 빨리 끝나는 회의 순
inline bool comp(Meeting a, Meeting b)
{
    // end가 같으면 start 기준 오름차순
    return a.end == b.end ? a.strat < b.strat : a.end < b.end;
}

int getCountMeetings(vector<Meeting>& meetingSchedule)
{
    // 회의 끝나는 시간 기준 오름차순
    sort(meetingSchedule.begin(), meetingSchedule.end(), comp);

    int cnt{ 0 }, endTime{ 0 };

    // Greedy
    for (int i = 0; i < meetingSchedule.size(); i++)
    {
        // 현재 회의 start가 이전 회의 end보다 
        // 늦거나 같으면 회의 선택 가능
        if (meetingSchedule[i].strat >= endTime)
        {
            ++cnt;
            endTime = meetingSchedule[i].end;
        }
    }

    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<Meeting> meetingSchedule(n);
    for (int i = 0; i < n; i++)
    {
        cin >> meetingSchedule[i].strat >> meetingSchedule[i].end;
    }

    cout << getCountMeetings(meetingSchedule) << '\n';


    return 0;
}
