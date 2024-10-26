#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

// DNA 1969 Greedy
// O( N * M )


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> dna(n);
    for (auto& d : dna)
    {
        cin >> d;
    }

    // Hamming Distance의 합이 가장 작은 DNA
    string resDna;
    resDna.reserve(m);
    // 해당 DNA의 Hamming Distance
    int hammingDist{ 0 };

    for (int i = 0; i < m; ++i)
    {
        // A, C, G, T 빈도수 카운팅
        array<int, 4> freq{ 0, 0, 0, 0 };
        // 각 DNA의 i번째 열의 뉴클레오타이드 빈도 계산
        for (const auto& d : dna)
        {
            switch (d[i])
            {
            case 'A': ++freq[0]; break;
            case 'C': ++freq[1]; break;
            case 'G': ++freq[2]; break;
            case 'T': ++freq[3]; break;
            }
        }

        // 현재 열 최빈 뉴클레타이드의 빈도수
        int maxCnt = *max_element(freq.begin(), freq.end());
        // 최빈 뉴클레오타이드 찾기
        char tmp = "ACGT"[
            find(freq.begin(), freq.end(), maxCnt) - freq.begin()
        ];

        // 최빈 뉴클레오 타이드 결과에 추가
        resDna += tmp;
        // Hamming Distance 계산
        hammingDist += n - maxCnt;
    }

    cout << resDna << "\n" << hammingDist;


    return 0;
}
