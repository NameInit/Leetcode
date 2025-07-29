#include <iostream>
#include <vector>


class Solution {
public:
	std::vector<int> smallestSubarrays(std::vector<int>& nums) {
		int n = nums.size();
		std::vector<int> ans(n, 1);
		std::vector<int> last(32, -1);

		for (int i = n - 1; i >= 0; --i) {
			for (int bit = 0; bit < 32; ++bit) {
				if (nums[i] & (1 << bit)) {
					last[bit] = i;
				}
			}
			int max_last = i;
			for (int bit = 0; bit < 32; ++bit) {
				if (last[bit] != -1) {
					max_last = std::max(max_last, last[bit]);
				}
			}
			ans[i] = max_last - i + 1;
		}
		return ans;
	}
};

// class Solution {
// public:
//     std::vector<int> smallestSubarrays(std::vector<int>& nums) {
//         int target=0, n=nums.size();
// 		for(const auto &num : nums){
// 			target|=num;
// 		}

// 		std::vector<int> ans;
// 		ans.reserve(n);
// 		for(int i = 0; i<n; ++i){
// 			int temp_ans=1;
// 			int temp_target=nums[i];
// 			for(int j=i+1; (j<n)&&(temp_target!=target); ++j){
// 				if(temp_target!=(temp_target|nums[j])){
// 					temp_ans=j-i+1;
// 					temp_target=temp_target|nums[j];
// 				}
// 			}
// 			ans.push_back(temp_ans);
// 		}

// 		return ans;
//     }
// };

int main(){
	Solution test;
	{
		std::vector<int> nums={1,0,2,1,3}; //3 3 2 2 1 
		for(const auto &i : test.smallestSubarrays(nums)){
			std::cout << i << ' ';
		}
		std::cout << std::endl;
	}
	{
		std::vector<int> nums={1,2}; //2 1
		for(const auto &i : test.smallestSubarrays(nums)){
			std::cout << i << ' ';
		}
		std::cout << std::endl;
	}
	{
		std::vector<int> nums={2,1}; //2 1
		for(const auto &i : test.smallestSubarrays(nums)){
			std::cout << i << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}