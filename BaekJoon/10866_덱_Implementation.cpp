#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

// 덱 10866 Implementation
// 그냥 구현
// O( n )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unordered_map<string, int> CMD_MAP = {
        {"push_front", 1}, {"push_back", 2},
        {"pop_front", 3},  {"pop_back", 4},
        {"size", 5},       {"empty", 6},
        {"front", 7},      {"back", 8}
    };

    int n;
    cin >> n;

    deque<int> dq;
    while (n--)
    {
        string cmd;
        cin >> cmd;

        switch (CMD_MAP[cmd])
        {
        case 1: {
            int x;
            cin >> x;
            dq.push_front(x);
            break;
        }
        case 2: {
            int x;
            cin >> x;
            dq.push_back(x);
            break;
        }
        case 3: {
            if (dq.empty()) cout << -1 << "\n";
            else 
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            break;
        }
        case 4: {
            if (dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            break;
        }
        case 5: {
            cout << dq.size() << "\n";
            break;
        }
        case 6: {
            cout << dq.empty() << "\n";
            break;
        }
        case 7: {
            cout << (dq.empty() ? -1 : dq.front()) << "\n";
            break;
        }
        case 8: {
            cout << (dq.empty() ? -1 : dq.back()) << "\n";
            break;
        }
        default:
            break;
        }
    }


    return 0;
}
