#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 먹을것인가_먹힐것인가 7795 BinarySearch


int getBigPairs(const vector<int>& A, const vector<int>& B)
{
    int cnt{ 0 };
    for (const int& a : A)
    {
        // B에서 a보다 작은 원소의 개수를 찾기
        cnt += lower_bound(B.begin(), B.end(), a) - B.begin();
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

        // B 벡터 오름차순 정렬
        sort(B.begin(), B.end());

        cout << getBigPairs(A, B) << "\n";
    }
    

    return 0;
}
