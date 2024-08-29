#include <iostream>
#include <unordered_set>

using namespace std;

// 로마숫자만들기 16922 BackTracking
// 순서 상관없이 모든 경우의 수 탐색
// O( 4^N )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    int roman[] = { 1, 5, 10, 50 }; // 로마 숫자 값
    unordered_set<int> sums;    // 가능한 모든 합 set

    // DFS
    auto DFS = [&](auto&& self, int depth, int start, int curSum) -> void {
        // n 개의 숫자를 선택했다면
        if (depth == n)
        {
            sums.insert(curSum);
            return;
        }

        // 현재 가능한 모든 숫자 선택
        for (int i = start; i < 4; ++i)
        {
            // depth 증가, 현재 합계에 숫자 선택값 더한 후 재귀 호출
            self(self, depth + 1, i, curSum + roman[i]);
        }
    };

    DFS(DFS, 0, 0, 0);

    // 합의 개수 출력
    cout << sums.size();


    return 0;
}
