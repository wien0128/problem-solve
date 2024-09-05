#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// 크면서작은수 2992 BackTracking
// 다음 순열을 찾으면 된다...
// O( N * N! )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string x;
    cin >> x;

    vector<bool> isUsed(x.size(), false);   // 각 자리 사용 여부
    string cur;         // 현재 순열
    int tmp{ stoi(x) }; // 원래 x 값
    int res{ -1 };      // 결과값, -1은 정답 없음 의미

    sort(x.begin(), x.end());   // 오름차순

    auto DFS = [&](auto&& self) -> void {
        // 모든 자릿수를 선택했다면
        if (cur.size() == x.size())
        {
            int n = stoi(cur);
            // tmp < n < res 유효한지 확인
            if (n > tmp && (res == -1 || n < res))
            {
                res = n;
            }
            return;
        }

        // 각 자리를 순서대로 순열 생성
        for (size_t i = 0; i < x.size(); ++i)
        {
            // 중복 선택 방지
            if (isUsed[i] || (i > 0 && x[i] == x[i - 1] && !isUsed[i - 1]))
            {
                continue;
            }

            isUsed[i] = true;
            cur.push_back(x[i]);

            self(self);

            // 백트래킹
            isUsed[i] = false;
            cur.pop_back();
        }
        };

    DFS(DFS);

    cout << (res == -1 ? 0 : res);
    

    return 0;
}
