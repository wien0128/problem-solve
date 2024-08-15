#include <iostream>
#include <set>
#include <unordered_map>
#include <string>

using namespace std;

// 문제추천시스템 21939 PriorityQueue
// O( NlogN + MlogN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // {난이도, 번호}, 난이도 기준 최소 힙
    set<pair<int, int>> problems;
    // 번호-난이도 
    unordered_map<int, int> dict;

    for (int i = 0; i < n; ++i)
    {
        int p, l;
        cin >> p >> l;
        problems.insert({ l, p });  // {난이도, 번호}
        dict[p] = l;                // [번호] = 난이도
    }

    int m;
    cin >> m;

    while (m--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "recommend")
        {
            int x; cin >> x;

            if (x == 1)
            {
                // 가장 어려운 문제 출력
                cout << problems.rbegin()->second << "\n";
            }
            else
            {
                // 가장 쉬운 문제 출력
                cout << problems.begin()->second << "\n";
            }
        }
        else if (cmd == "add")
        {
            int p, l; cin >> p >> l;
            problems.insert({ l, p });
            dict[p] = l;
        }
        else if (cmd == "solved")
        {
            int p; cin >> p;
            int l = dict[p];            // 번호로 난이도 조회
            problems.erase({ l, p });   // 해당 난이도와 번호 set 삭제
            dict.erase(p);              // 번호-난이도 map 삭제
        }
    }


    return 0;
}
