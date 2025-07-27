#include <iostream>
#include <vector>
#include <cassert>


class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
		int ans=0, n=nums.size();
		int state=0; // state=1 - down->up; state=-1 up->down; state=0 undefined;
		for(int i=1; i<n; ++i){
			if(nums[i]>nums[i-1]){
				ans+=(state==-1);
				state=1;
			}
			else if(nums[i]<nums[i-1]){
				ans+=(state==1);
				state=-1;
			}
		}
		return ans;
    }
};

int main(){
	Solution test;
	{
		std::vector<int> nums={2,4,1,1,6,5};
		assert(3 == test.countHillValley(nums));
	}
	{
		std::vector<int> nums={6,6,5,5,4,1};
		assert(0 == test.countHillValley(nums));
	}
	return 0;
}