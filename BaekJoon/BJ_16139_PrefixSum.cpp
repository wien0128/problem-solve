#include <iostream>
#include <string>
#include <vector>

using namespace std;
constexpr int ALPHABET_SIZE{ 26 };
using alphabetAcc = vector<vector<int>>;

// 백준 16139 Prefix Sum
// 쪼끔 어려웠다

// alphabet[i][j] 
// = 문자열 시작부터 j-1까지 등장한 i번째 알파벳('a' + i)의 등장 횟수(누적합)

// str 기반 누적합 배열 반환
auto setAccSum(const string& str) -> alphabetAcc
{
    // 26개 알파벳에 대응하는 누적합 벡터
    alphabetAcc accSum(ALPHABET_SIZE, vector<int>(str.length() + 1, 0));

    // 문자열의 각 문자에 대해 순휘
    for (int i = 0; i < str.length(); ++i)
    {
        // 모든 알파벳에 대해 이전 누적값을 현재 위치에 복사
        for (auto j = 0; j < ALPHABET_SIZE; ++j)
        {
            accSum[j][i + 1] = accSum[j][i];
        }
        // 현재 문자의 누적합 증가
        accSum[str[i] - 'a'][i + 1]++;
    }

    return accSum;
}

// l ~ r 사이에서 a의 등장 횟수 반환
auto getAlphabetCnt(const alphabetAcc& alphabet, char a, int l, int r) -> int
{
    // 문자 a의 r까지의 등장 횟수 - 문자 a의 l - 1까지의 등장 횟수
    return alphabet[a - 'a'][r] - alphabet[a - 'a'][l - 1];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;      // 질문 개수
    string str;     // 문자열
    cin >> str >> q;
    
    // str에 대한 누적합 배열
    alphabetAcc alphabet = setAccSum(str);
    
    while (q--)
    {
        int l, r;   // 범위 l ~ r
        char a;     // 찾는 문자
        cin >> a >> l >> r;
        l++; r++; // ++ for 1-based indexing

        cout << getAlphabetCnt(alphabet, a, l, r) << "\n";
    }
    

    return 0;
}
