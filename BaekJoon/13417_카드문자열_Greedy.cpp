#include <iostream>
#include <deque>

using namespace std;

// 카드문자열 13417 Greedy
// O( t * n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        deque<char> res;

        while (n--)
        {
            char card;
            cin >> card;
            
            // 알파벳 순서가 빠를수록 사전 순에서 앞섬
            // 따라서, 작은 문자를 앞에 추가해야 함
            // 현재 카드가 res에서 가장 작은 문자 보다 작거나 같을 경우
            if (res.empty() || card <= res.front())
            {
                // 앞에 추가
                res.push_front(card);
            }
            else
            {
                // 뒤에 추가
                res.push_back(card);
            }
        }

        for (char c : res) cout << c;
        cout << '\n';
    }

    
    return 0;
}
