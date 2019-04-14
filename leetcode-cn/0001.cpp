#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		const int nums_size = nums.size();
		vector<int> result;

		for (int i = 0; i < nums_size; i++)
		{
			for (int j = 0; j < nums_size; j++)
			{
				if (i == j) continue;
				if (nums[i] + nums[j] == target)
				{
					
					result.push_back(i);result.push_back(j);
					return result;
				}
			}
		}   
		return result;
    }
};