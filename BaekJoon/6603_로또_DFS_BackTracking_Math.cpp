#include <iostream>
#include <vector>

using namespace std;

// 로또 6603 DFS, BackTracking, Math
// O( kC6 )


void DFS(const vector<int>& s, vector<int>& cur, int start, int depth)
{
    // 6개 숫자를 모두 선택했다면 출력
    if (depth == 6)
    {
        for (int i = 0; i < 6; ++i)
        {
            cout << cur[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 현재 위치부터 가능한 모든 숫자 재귀 선택
    for (int i = start; i <= s.size() - 6 + depth; ++i)
    {
        cur[depth] = s[i];
        DFS(s, cur, i + 1, depth + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int k;
    while (cin >> k && k != 0)
    {
        vector<int> s(k);
        for (int& e : s)
        {
            cin >> e;
        }
        
        vector<int> cur(6); // 6개 로또 벡터
        
        DFS(s, cur, 0, 0);

        cout << "\n";
    }


    return 0;
}
