class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> temp;
		for (int i = 0; i < nums.size(); i++){
			if (temp.find(nums[i]) != temp.end())
				return {temp.find(nums[i])->second,i};
			temp.insert(make_pair(target - nums[i], i));
		}
		return {};
	}
};