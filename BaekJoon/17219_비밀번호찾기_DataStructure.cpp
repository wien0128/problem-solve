#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// 비밀번호찾기 17219 DataStructure
// O( n + m )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> passwordMap;
    string site, password;

    // 사이트별 비밀번호 입력
    while (n--)
    {
        cin >> site >> password;
        passwordMap[site] = password;
    }
    // 사이트 비밀번호 출력
    while (m--)
    {
        cin >> site;
        cout << passwordMap[site] << '\n';
    }


    return 0;
}
