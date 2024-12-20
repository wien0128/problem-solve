#include <iostream>
#include <vector>

using namespace std;

// 스위치켜고끄기 1244 Implementation
// 지문이 상당히 난삽한 문제...
// O( m * n ), 입력 크기 n, 학생 수 m


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> switches(n);    // 스위치
    for (int& s : switches) cin >> s;

    int st;                    // 학생수
    cin >> st;

    while (st--)
    {
        int gen, num;
        cin >> gen >> num;

        // 남학생일 경우 num의 배수번째 스위치 토글
        if (gen == 1)
        {
            for (int i = num - 1; i < n; i += num)
            {
                switches[i] ^= 1;
            }
        }
        // 여학생일 경우 좌우 대칭 범위 내 스위치 토글
        else
        {
            // 투 포인터
            int l = num - 2, r = num;
            // 현재 위치 토글
            switches[num - 1] ^= 1;
            // 상태가 동일하다면 토글 후 다음 인덱스로 이동
            // 다르다면, 종료
            while (l >= 0 && r < n && switches[l] == switches[r])
            {
                switches[l--] ^= 1;
                switches[r++] ^= 1;
            }
        }
    }
    
    // 20번째 스위치마다 줄바꿈
    for (int i = 0; i < n; ++i)
    {
        cout << switches[i] << (i % 20 == 19 ? "\n" : " ");
    }


    return 0;
}
