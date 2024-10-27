#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 차집합 1822 Sorting
// O( NlogN + MlogM )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> setA(n), setB(m);
    for (int& x : setA) cin >> x;
    for (int& x : setB) cin >> x;

    sort(setB.begin(), setB.end());

    vector<int> res;
    res.reserve(n);

    // 집합 A의 원소가 집합 B에 없을 경우
    // res에 추가
    for (int& x : setA)
    {
        if (!binary_search(setB.begin(), setB.end(), x))
        {
            res.push_back(x);
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for (int& x : res)
    {
        cout << x << ' ';
    }

    /*
    set<int> setA, setB;
    // 집합 A와 B 입력
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        setA.insert(x);
    }
    for (int i = 0; i < m; ++i)
    {
        int x; cin >> x;
        setB.insert(x);
    }
    
    // 집합 A - 집합 B 계산
    vector<int> res;
    set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), 
                    back_inserter(res));

    cout << res.size() << '\n';
    for (const auto& x : res)
    {
        cout << x << ' ';
    }
    */

    return 0;
}
