#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <array>
#include <cassert>


// //хе-хе я не чекнул тесты, подумал, что надо вывести только уникальные, а там другое просят)
// class Solution {
// public:
//     int maximumUniqueSubarray(std::vector<int>& nums) {
//         std::unordered_set<int> unique;
// 		std::unordered_set<int> check;
// 		for(const auto &num : nums){
// 			if(check.find(num)==check.end()){
// 				check.insert(num);
// 				unique.insert(num);
// 			}
// 			else if(auto fount_item = unique.find(num); fount_item!=unique.end()){
// 				unique.erase(fount_item);
// 			}
// 		}
// 		for(const auto &item : unique){
// 			std::cout << item << ' ';
// 		}
// 		return std::accumulate(unique.begin(), unique.end(),0);
//     }
// };

//first version
// class Solution {
// public:
//     int maximumUniqueSubarray(std::vector<int>& nums) {
//         std::unordered_set<int> unique;
// 		int left=0, right=0, ans=0, temp_ans=0;
// 		int n=nums.size();
// 		while(right<n){
// 			if(auto found_item = unique.find(nums[right]); found_item==unique.end()){
// 				unique.insert(nums[right]);
// 				temp_ans+=nums[right];
// 				ans=std::max(ans,temp_ans);
// 				++right;
// 			}
// 			else{
// 				while(unique.find(nums[right])!=unique.end()){
// 					unique.erase(nums[left]);
// 					temp_ans-=nums[left];
// 					++left;
// 				}
// 			}
// 		}
// 		return ans;
//     }
// };

//first version + refactoring
// class Solution {
// public:
// 	int maximumUniqueSubarray(std::vector<int>& nums) {
// 		std::unordered_set<int> unique;
// 		int left = 0, ans = 0, temp_ans = 0;
// 		for (int right = 0; right < nums.size(); ++right) {
// 			while (unique.count(nums[right])) {
// 				unique.erase(nums[left]);
// 				temp_ans -= nums[left++];
// 			}
// 			unique.insert(nums[right]);
// 			temp_ans += nums[right];
// 			ans = std::max(ans, temp_ans);
// 		}
// 		return ans;
// 	}
// };

//the best version
class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
		std::array<int, 10001> ps{};
		int temp_ans=0, ans=0, diff_ps=0;		

		for(const auto &num : nums){
			temp_ans+=num;
			diff_ps=std::max(diff_ps, ps[num]);
			ans=std::max(ans, temp_ans-diff_ps);
			ps[num]=temp_ans;
		}

		std::cout << ans << std::endl;
        return ans;
    }
};

int main(){
	Solution test;
	{
		std::vector<int> nums = {4,2,4,5,6};
		assert(17 == test.maximumUniqueSubarray(nums));
	}
	{
		std::vector<int> nums = {5,2,1,2,5,2,1,2,5};
		assert(8 == test.maximumUniqueSubarray(nums));
	}
	{
		std::vector<int> nums = {187,470,25,436,538,809,441,167,477,110,275,133,666,345,411,459,490,266,987,965,429,166,809,340,467,318,125,165,809,610,31,585,970,306,42,189,169,743,78,810,70,382,367,490,787,670,476,278,775,673,299,19,893,817,971,458,409,886,434};
		assert(16911 == test.maximumUniqueSubarray(nums));
	}
	return 0;
}