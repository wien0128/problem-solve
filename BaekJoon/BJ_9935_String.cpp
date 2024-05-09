#include <iostream>
#include <string>

using namespace std;

// 백준 9935 string
// 스택이 필요할 줄 알았는데
// 딱히 필요 없는 문제


string explodeString(string str, const string& bomb)
{
    string res;   // 결과 문자열
    for (char ch : str)
    {
        res.push_back(ch);

        // 1. res의 길이가 폭발 문자열의 길이 보다 길거나 같은가?
        // 2. res의 끝에서 bomb 길이만큼의 문자열이 bomb과 같은가?
        if (res.size() >= bomb.size() && res.substr(res.size() - bomb.size()) == bomb)
        {
            // EXPLOSION as much as bomb length
            res.erase(res.size() - bomb.size());
        }
    }

    return res.empty() ? "FRULA" : res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string str;     // 입력 문자열
    string bomb;    // 폭발 문자열
    cin >> str >> bomb;

    cout << explodeString(str, bomb) << "\n";

    
    return 0;
}
