#include <iostream>
#include <string>

using namespace std;

// 부분문자열 6550 Greedy
// O( N * M ), N = s.length(), M = t.length()


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t;
    
    while (cin >> s >> t)
    {
        auto it = t.begin();
        bool isFound = true;
        
        // 순차적으로 s의 문자들을 t에서 찾음
        for (char c : s)
        {
            it = find(it, t.end(), c);
            // 찾지 못했을 경우
            if (it == t.end())
            {
                cout << "No\n";
                isFound = false;
                break;
            }
            // 찾았다면 다음 칸으로 이동
            ++it;
        }
        // s의 모든 문자를 t에서 순차적으로 찾았다면
        if (isFound)
        {
            cout << "Yes\n";
        }
    }


    return 0;
}
