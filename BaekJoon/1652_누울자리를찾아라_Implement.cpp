#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 누울자리를찾아라 1652 Implement
// O( N^2 )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 방 벡터
    vector<string> room(n);
    for (auto& r : room) cin >> r;

    // 세로, 가로로 누울 자리 개수
    int hor{ 0 }, ver{ 0 };

    for (int i = 0; i < n; ++i)
    {
        // 각 가로/세로 방향 대한 '.' 길이 추적
        int hSpace = 0, vSpace = 0;

        for (int j = 0; j < n; ++j)
        {
            // 가로 공간 탐색
            if (room[i][j] == '.') ++hSpace;    // '.'이면 공간 길이 증가
            else
            {
                // 'X'를 만났다면
                // 연속된 '.'이 2 보다 크다면 누울 자리 증가
                hor += (hSpace >= 2);
                // '.' 공간 길이 초기화
                hSpace = 0;
            }

            // 세로 공간 탐색
            if (room[j][i] == '.') ++vSpace;    // '.'이면 공간 길이 증가
            else
            {
                // 'X'를 만났다면
                // 연속된 '.'이 2 보다 크다면 누울 자리 증가
                ver += (vSpace >= 2);
                // '.' 공간 길이 초기화
                vSpace = 0;
            }
        }

        // 마지막 칸까지 '.'일 경우 처리
        hor += (hSpace >= 2);
        ver += (vSpace >= 2);
    }
    
    // 가로/세로 누울 자리 개수 출력
    cout << hor << " " << ver;


    return 0;
}
