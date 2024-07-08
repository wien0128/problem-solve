#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 먹을것인가_먹힐것인가 7795 TwoPointer


int getBigPairs(const vector<int>& A, const vector<int>& B)
{
    int cnt{ 0 };
    int j{ 0 };
    
    for (const int& a : A)
    {
        // B에서 a보다 작은 원소의 개수 찾기
        while (j < B.size() && B[j] < a)
        {
            j++;
        }
        // j는 현재 a보다 작은 B의 원소 개수
        cnt += j;
    }

    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> A(n);
        vector<int> B(m);

        for (int& a : A) cin >> a;
        for (int& b : B) cin >> b;

        // 오름차순
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        cout << getBigPairs(A, B) << "\n";
    }
    

    return 0;
}
