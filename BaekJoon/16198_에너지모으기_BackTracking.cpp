#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 에너지모으기 16198 BackTracking
// O( (N - 2)! )


int getMaxEnergy(vector<int>& beads)
{
    // 구슬이 2개만 남을 경우 
    if (beads.size() == 2) return 0;

    int maxEnergy{ 0 };

    for (size_t i = 1; i < beads.size() - 1; ++i)
    {
        // 현재 구슬 제거하여 얻을 수 있는 에너지
        int energy = beads[i - 1] * beads[i + 1];

        // 제거 할 구슬 저장 후 제거
        int removeBead = beads[i];
        beads.erase(beads.begin() + i);

        // 남은 구슬들에 대해 최대 에너지 재귀 계산
        maxEnergy = max(maxEnergy, energy + getMaxEnergy(beads));

        // 백트래킹
        beads.insert(beads.begin() + i, removeBead);
    }

    return maxEnergy;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> beads(n);
    for (int& b : beads) cin >> b;

    cout << getMaxEnergy(beads);

    
    return 0;
}
