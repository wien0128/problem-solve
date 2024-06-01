#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

// 백준 11286 Priority Queue


struct cmp
{
    bool operator() (ll op1, ll op2)
    {
        ll absOp1 = abs(op1);
        ll absOp2 = abs(op2);
        // op1 > op2, 오름차순 = 루트에 최소값 
        // op1 < op2, 내림차순 = 루트에 최대값
        // 절대값이 같을 경우 원래값으로 비교
        // 절대값이 다를 경우 절대값으로 비교
        return (absOp1 == absOp2) ? (op1 > op2) : (absOp1 > absOp2);
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // 절대값을 기준으로 루트에 최소값을 가짐
    priority_queue<ll, vector<ll>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        if (x == 0)
        {
            if (pq.empty())
            {
                cout << 0 << "\n";
                continue;
            }

            cout << pq.top() << "\n";
            pq.pop();
        }
        else
        {
            pq.push(x);
        }
    }

    return 0;
}
