#include <vector>
#include <unordered_map>

using namespace std;

// leetcode 1 Array
// 보충수와 unordered_map 사용

class Soultion {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		// nums[i]가 키, 인덱스가 값
		unordered_map<int, int> map;

		for (int i = 0; i < nums.size(); ++i)
		{
			// 보충수
			int complement = target - nums[i];

			// 보충수를 찾으면 정답
			if (map.find(complement) != map.end())
			{
				return { map[complement], i };
			}

			// 찾지 못하면 값-인덱스 꼴로 삽입
			map[nums[i]] = i;
		}

		// target을 만들지 못함.
		return {};
	}
};
