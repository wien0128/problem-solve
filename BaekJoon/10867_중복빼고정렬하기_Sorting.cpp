#include <iostream>
#include <set>

using namespace std;

// 중복빼고정렬하기 10867 Sorting
// O( N logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    for (const int& e : s)
    {
        cout << e << " ";
    }

    
    return 0;
}
