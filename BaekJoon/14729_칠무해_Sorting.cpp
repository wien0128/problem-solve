#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

// 칠무해 14729 Sorting
// O( n log n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<double> v;

    int n;
    cin >> n;

    // 메모리 재할당 방지
    v.reserve(n);

    // 최소 힙, move() 복사 비용 제거
    priority_queue pq(greater<double>(), move(v));

    while (n--)
    {
        double score;
        cin >> score;

        pq.emplace(score);
    }

    // 소수점 3자리까지 출력
    cout << fixed << setprecision(3);

    for (int i = 0; i < 7; ++i)
    {
        // 가장 작은 상위 7개 값만 출력
        cout << pq.top() << "\n";
        pq.pop();
    }


    return 0;
}
