#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

// 수학숙제 2870 Sorting
// long long 범위(64 bit)를 
// 넘어서는 숫자가 들어올 수 있다
// O( (NM)log(NM) )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string> res;

    while (n--)
    {
        string input;
        cin >> input;

        string curNum;

        for (char c : input)
        {
            // 숫자면 curNum에 추가
            // 아니라면, res 벡터에 추가 후 비우기
            if (isdigit(c))
            {
                curNum += c;
            }
            else if (!curNum.empty())
            {
                res.push_back(curNum);
                curNum.clear();
            }
        }

        // 남은 숫자 처리
        if (!curNum.empty())
        {
            res.push_back(curNum);
        }
    }

    // 각 숫자 앞에 위치한 0들만 제거
    // npos(-1)가 반환된다면 모든 숫자가 0
    // 따라서, min()을 예외처리
    for (string& num : res)
    {
        num.erase(0, min(num.find_first_not_of('0'), num.size() - 1));
    }

    // 길이순 비교 후 같은 길이라면 사전순 비교
    // 오름차순 = 비내림차순
    sort(res.begin(), res.end(), [](const string& a, const string& b) {
        return a.size() != b.size() ? a.size() < b.size() : a < b;
        });

    for (const string &num : res)
    {
        cout << num << "\n";
    }


    return 0;
}
