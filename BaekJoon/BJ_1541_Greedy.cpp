#include <iostream>
#include <string>

using namespace std;

// 백준 1541 Greedy
// 첫 번쨰 '-' 이전 모든 수를 더하고
// '-' 이후의 모든 수를 빼는 그리디 알고리즘


// 최소값 반환
int getMinReult(const string& expression)
{
    int res{ 0 }, tmp{ 0 };
    bool isMinus{ false };
    string num{ "" };

    // 마지막 숫자 처리를 위한 '+'
    for (char c : expression + '+')
    {
        // 연산자 or 숫자?
        if (c == '+' || c == '-')
        {
            if (isMinus)
            {
                res -= stoi(num);
            }
            else
            {
                res += stoi(num);
            }
            num = "";   // 연산 후 새로운 숫자를 위해 비우기
            if (c == '-') isMinus = true;
        }
        else
        {
            num += c;
        }
    }

    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string expression;
    cin >> expression;

    cout << getMinReult(expression);


    return 0;
}
