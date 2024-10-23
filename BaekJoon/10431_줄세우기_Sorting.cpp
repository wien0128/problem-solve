#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 줄세우기 10431 Sorting
// 삽입 정렬을 이진 탐색으로 최적화
// 걍 나이브하게 풀어도 똑같은 문제
// O( T * N log N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int p;
    cin >> p;

    while (p--)
    {
        int t, backward{ 0 };
        cin >> t;

        vector<int> line;
        for (int i = 0; i < 20; ++i)
        {
            int h;
            cin >> h;

            // 새 학생의 자리 찾기
            auto pos = lower_bound(line.begin(), line.end(), h);
            // 새 학생을 삽입해야 할 
            // 인덱스 뒤 모든 학생들의 이동 거리
            backward += line.end() - pos;
            // 새 학생 삽입
            line.insert(pos, h);
        }

        cout << t << " " << backward << "\n";
    }


    return 0;
}
