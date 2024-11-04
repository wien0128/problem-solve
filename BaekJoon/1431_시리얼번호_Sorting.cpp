#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

// 시리얼번호 1431 Sorting
// O( n * m * log n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 기타 이름 벡터 및 저장
    vector<string> v(n);
    for (string& e : v) cin >> e;

    // 조건에 맞게 정렬
    sort(v.begin(), v.end(), [](const string &a, const string &b) {
        // 1. 문자열 길이가 짧은 것이 우선
        if (a.size() != b.size()) return a.size() < b.size();

        // 2. 문자열에 포함된 숫자 합이 작은 것이 우선
        int sumA{ 0 }, sumB{ 0 };
        for (char c : a) if (isdigit(c)) sumA += c - '0';
        for (char c : b) if (isdigit(c)) sumB += c - '0';
        if (sumA != sumB) return sumA < sumB;

        // 3. 사전순 정렬
        return a < b;
    });

    for (const string& e : v)
    {
        cout << e << "\n";
    }

    
    return 0;
}
