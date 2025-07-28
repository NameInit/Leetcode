#include <iostream>
#include <vector>
#include <cassert>


class Solution {
public:
    int countMaxOrSubsets(std::vector<int>& nums) {
		int target=0;
		for(const auto &num : nums){
			target|=num;
		}

		auto calc = [&nums,&target, n=nums.size()](auto &&self,int i, int temp){
			if(i==n){
				return static_cast<int>(temp == target);
			}
			return self(self, i+1,temp|nums[i]) + self(self, i+1, temp);
		};
		
        return calc(calc,0,0);
    }
};

int main(){
	Solution test;
	{
		std::vector<int> nums={3,1};
		assert(2 == test.countMaxOrSubsets(nums));
	}
	{
		std::vector<int> nums={2,2,2};
		assert(7 == test.countMaxOrSubsets(nums));
	}
	{
		std::vector<int> nums={3,2,1,5};
		assert(6 == test.countMaxOrSubsets(nums));
	}
	return 0;
}