#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>

using namespace std;
using Applicants = vector<pair<int, int>>;

// 백준 1946 Greedy_C++20
// 그리디 보단 독해 문제 같은 문제


int getSelectApplicants(Applicants& applicants, int n)
{
    ranges::sort(applicants); // 서류 점수 기준 오름차순 정렬

    int bestInterviewRank{ applicants[0].second }; // 서류 1등의 면접 성적
    int res{ 1 };   // 서류 1등은 면접 성적과는 무관하게 뽑음
    for (const auto& [paperRank, interviewRank] : applicants | views::drop(1))
    {
        // 현재 지원자의 면접 성적이 현재까지의 최고 면접 성적보다 좋을 경우
        if (bestInterviewRank > interviewRank)
        {
            res++;
            bestInterviewRank = interviewRank; // 최고 면접 성적 갱신
        }
    }

    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        Applicants applicants(n); // vector<pair<서류점수, 면접점수>>
        for (auto& [paperRank, interviewRank] : applicants)
        {
            cin >> paperRank >> interviewRank;
        }

        cout << getSelectApplicants(applicants, n) << "\n";
    }

    
    return 0;
}
