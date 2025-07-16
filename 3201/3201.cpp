#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <cassert>


class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        std::array<int,4> ans{}; //even-even, odd-odd, even-odd, odd-even
		for(const auto &num : nums){
			ans[0]+=num%2;
			ans[1]+=!(num%2);
			ans[2]+=(ans[2]%2==num%2);
			ans[3]+=(ans[3]%2==!(num%2));
		}
		return *std::max_element(ans.begin(), ans.end());
    }
};

int main(){
	Solution test;
	{
		std::vector<int> nums = {1, 2, 3, 4};
		assert(4 == test.maximumLength(nums));
	}
	return 0;
}