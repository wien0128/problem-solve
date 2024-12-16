#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// 끝말잇기 28432 String, Implementation
// 구현이 살짝 까다로운 문제
// O( n + m )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string> s(n);        // 끝말잇기 벡터
    unordered_set<string> st;   // 중복 확인용 단어 셋
    int idx{ -1 };              // '?' 인덱스
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];

        if (s[i] == "?") idx = i;
        else st.emplace(s[i]);
    }

    int m;
    cin >> m;

    // 각 후보 단어 확인
    for (int i = 0; i < m; ++i)
    {
        string str;
        cin >> str;

        // 이미 존재하는 단어라면 건너뜀
        if (st.count(str)) continue;

        // 벡터 범위 내에서
        // 후보 단어 첫 문자 != 이전 단어 마지막 문자
        if (idx > 0 && str.front() != s[idx - 1].back()) continue;
        // 후보 단어 마지막 문자 != 다음 단어 첫 문자
        if (idx + 1 < n && str.back() != s[idx + 1].front()) continue;

        // 조건을 만족하면 정답 단어
        cout << str;
        return 0;
    }


    return 0;
}
