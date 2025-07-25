#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <cassert>


class Solution {
public:
    int maxSum(std::vector<int>& nums) {
		std::unordered_set<int> unique;
		int max_negative=-101;
		for(const auto &num : nums){
			if(num>0) unique.insert(num); 
			else max_negative=std::max(max_negative, num);
		}
		int ans=std::accumulate(unique.begin(), unique.end(),0);
		return ans ? ans : max_negative;
    }
};

int main(){
	Solution test;
	{
		std::vector<int> nums={1,2,3,4,5};
		assert(15 == test.maxSum(nums));
	}
	{
		std::vector<int> nums={1,1,0,1,1};
		assert(1 == test.maxSum(nums));
	}
	{
		std::vector<int> nums={1,2,-1,-2,1,0,-1};
		assert(3 == test.maxSum(nums));
	}
	return 0;
}