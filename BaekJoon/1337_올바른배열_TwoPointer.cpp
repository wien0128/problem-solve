#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 올바른배열 1337 TwoPointer


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& v : arr)
    {
        cin >> v;
    }

    // 오름차순 정렬
    sort(arr.begin(), arr.end());
    
    int j{ 0 }; // 투 포인터
    int res{ 5 }; // 최소 추가 숫자 개수
    
    // 투 포인터를 활용한 풀이
    for (int i = 0; i < n; ++i)
    {
        // 현재 포인터 i부터 5개 연속 숫자를 찾기
        while (j < n && arr[j] <= arr[i] + 4)
        {
            ++j;
        }
        // 현재 범위 내의 숫자 개수를 구하고, 필요한 숫자 개수 업데이트
        res = min(res, 5 - (j - i));
    }
    
    // STL 활용 풀이, 논리는 위와 같다.
    for (int i = 0; i < n; ++i)
    {
        // arr[i]부터 범위 내에 있는 숫자 개수 계산
        int need = distance(arr.begin() + i, lower_bound(arr.begin(), arr.end(), arr[i] + 5));
        // 추가로 필요한 숫자 개수 업데이트
        res = min(res, 5 - need);
    }

    // Set을 활용한 풀이, 중복을 허용하지 않기에 단순 체킹
    set<int> st;
    while (n--)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    for (auto& x : st)
    {
        int cnt{ 4 };
        for (int i = 1; i < 5; ++i)
        {
            if (st.count(x + i))
                --cnt;
        }
        res = min(res, cnt);
    }

    cout << res;


    return 0;
}
