#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 1
vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    // 빈 배열은 바로 반환
    if (arr.empty()) return answer;
    
    // 첫 요소는 무조건 추가
    answer.push_back(arr[0]);
    
    // 이전 값과 같은지 순회하며 비교
    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] != arr[i - 1])
        {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}

// 2
vector<int> solution(vector<int> arr) 
{   
    // 중복 값을 찾고 지움
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> answer = arr;

    return answer;
}
