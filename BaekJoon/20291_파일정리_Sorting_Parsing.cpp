#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 파일정리 20291 Sorting, Parsing
// O( n + k log k )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // {확장자, 등장 빈도}
    unordered_map<string, int> extCnt;

    while (n--)
    {
        string filename;
        cin >> filename;

        // '.'의 위치를 찾은 후 '.' 이후 문자열 파싱
        size_t dotPos = filename.find_last_of('.');
        string ext = filename.substr(dotPos + 1);

        // 현재 확장자 빈도 수 증가, 없다면 0으로 초기화 후 증가
        ++extCnt[ext];
    }

    // 정렬을 위해 벡터로 변환 후 확장자 기준 사전순 정렬
    vector<pair<string, int>> res(extCnt.begin(), extCnt.end());
    sort(res.begin(), res.end());

    // 구조적 바인딩을 이용한 출력
    for (const auto& [ext, cnt] : res)
    {
        cout << ext << ' ' << cnt << "\n";
    }


    return 0;
}
