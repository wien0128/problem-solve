#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 숫자놀이 1755 Sorting, String
// O( (n - m + 1) * log(n - m + 1) )


// 숫자 -> 영단어 변환
string numToWord(int num) 
{
    static const vector<string> WORDS = { "zero", "one", "two", "three",
        "four", "five", "six", "seven", "eight", "nine" };

    // num 이 10을 넘을 경우 십의 자리 단어로 치환 후 공백 추가
    // 아니라면 num 바로 치환 후 반환
    return (num >= 10 ? WORDS[num / 10] + " " : "") + WORDS[num % 10];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;

    // { 영단어("seven"), 숫자(8) }
    vector<pair<string, int>> v;
    for (int i = m; i <= n; ++i) 
    {
        v.emplace_back(numToWord(i), i);
    }

    // 비교자 함수가 없다면 첫 번째 요소 기준 정렬
    // 여기선 영단어 기준 사전순 정렬
    sort(v.begin(), v.end());

    int len{ v.size() };
    for (int i = 0; i < len; ++i) 
    {
        // 10번째 숫자마다 줄바꿈
        cout << v[i].second << (i % 10 == 9 ? '\n' : ' ');
    }


    return 0;
}
