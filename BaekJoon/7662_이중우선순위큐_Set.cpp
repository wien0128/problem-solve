#include <iostream>
#include <set>

using namespace std;
using ll = long long;

// 이중우선순위큐 7662 set
// 양방향 반복자를 지원하는 set을 쓰면 난이도가 확 내려간다.
// O( T * K logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int k;
        cin >> k;

        multiset<ll> ms;    // 오름차순(최소 힙)

        for (int i = 0; i < k; ++i)
        {
            char cmd;   // 명령어
            ll num;     // 숫자
            cin >> cmd >> num;

            if (cmd == 'I') // 숫자 삽입
            {
                ms.insert(num);
            }
            else if (cmd == 'D') // 숫자 삭제
            {
                if (!ms.empty())
                {
                    if (num == 1)   // 최대값 삭제
                    {
                        auto it = prev(ms.end());
                        ms.erase(it);
                    }
                    else if (num == -1) // 최소값 삭제
                    {
                        auto it = ms.begin();
                        ms.erase(it);
                    }
                }
            }
        }

        if (ms.empty()) // set 이 비었을 경우
        {
            cout << "EMPTY\n";
        }
        else
        {
            // "최대값(set 의 끝값) 최소값(set 의 시작값)
            cout << *ms.rbegin() << " " << *ms.begin() << "\n";
        }
    }


    return 0;
}
