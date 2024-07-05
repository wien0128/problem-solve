#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 주몽 1940 TwoPointer
// 정렬을 하면 탐색이 효율적이다.


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> materials(n);
    for (auto& m : materials)
    {
        cin >> m;
    }
    
    // 오름차순 정렬
    sort(materials.begin(), materials.end());

    // 투 포인터
    int start{ 0 }, end{ n - 1 };
    // 만들 수 있는 갑옷 수
    int cnt{ 0 };

    // 양 끝에서 부터 탐색
    while (start < end)
    {
        int sum{ materials[start] + materials[end] };
        
        // 갑옷을 만들 수 있으면
        if (sum == m)
        {
            // 개수 증가 후 탐색 범위 축소
            ++cnt;
            ++start;
            --end;
        }
        else if (sum < m)
        {
            ++start;
        }
        else
        {
            --end;
        }
    }

    cout << cnt;


    return 0;
}
