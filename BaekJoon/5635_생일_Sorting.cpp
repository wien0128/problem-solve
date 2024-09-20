#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

// 생일 5635 Sorting
// O( N logN )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // <이름, 일, 월, 연>
    vector<tuple<string, int, int, int>> vt(n);

    for (auto& [name, d, m, y] : vt)
    {
        cin >> name >> d >> m >> y;
    }

    sort(vt.begin(), vt.end(), [](auto& a, auto& b) {
        return tie(get<3>(a), get<2>(a), get<1>(a)) < tie(get<3>(b), get<2>(b), get<1>(b));
        });

    cout << get<0>(vt.back()) << "\n";
    cout << get<0>(vt.front());
    
    /*
        Second Way
       
        vector<tuple<int, int, int, string>> vt(n);
     
        for (auto& [y, m, d, name] : vt)
            cin >> name >> d >> m >> y;
     
        cout << get<3>(*max_element(vt.begin(), vt.end())) << "\n";
        cout << get<3>(*min_element(vt.begin(), vt.end()));
    */

    return 0;
}
