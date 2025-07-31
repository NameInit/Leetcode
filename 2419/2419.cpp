#include <iostream>
#include <vector>
#include <cassert>


class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int ans=1, temp_ans=1, max_num=nums[0], n=nums.size();
		for(int i=1; i<n; ++i){
			if(max_num<nums[i]){
				max_num=nums[i];
				ans=1;
			}
			temp_ans=((nums[i]==nums[i-1])&&(max_num==nums[i])) ? temp_ans+1 : 1;
			if(temp_ans>ans)
				++ans;
		}
		return ans;
    }
};


int main(){
	Solution test;
	{
		std::vector<int> nums={1,2,3,3,2,2};
		assert(2 == test.longestSubarray(nums));
	}
	{
		std::vector<int> nums={25,25,25,26};
		assert(1 == test.longestSubarray(nums));
	}
	{
		std::vector<int> nums={1,2,3,4};
		assert(1 == test.longestSubarray(nums));
	}
	{
		std::vector<int> nums={1,2,3,4,5,6,6};
		assert(2 == test.longestSubarray(nums));
	}
	{
		std::vector<int> nums={100,99,100,2};
		assert(1 == test.longestSubarray(nums));
	}
	return 0;
}