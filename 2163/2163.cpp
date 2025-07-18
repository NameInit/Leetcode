#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <cassert>


class Solution {
public:
    long long minimumDifference(std::vector<int>& nums) {
        int n_mult_3 = nums.size();
		int n=n_mult_3/3;
		std::vector<long long> sum(n+1,0);
		std::priority_queue<int> left;

		for(int i=0; i<n; ++i){
			left.push(nums[i]);
			sum[0]+=nums[i];
		}

		for(int i=0; i<n; i++){
			left.push(nums[i+n]);
			sum[i+1]=sum[i]-left.top()+nums[i+n];
			left.pop();
		}

		long long cur_sum_right = 0;
		std::priority_queue<int, std::vector<int>, std::greater<int>> right;
		for(int i=0; i<n; i++){
			cur_sum_right+=nums[n_mult_3-1-i];
			right.push(nums[n_mult_3-1-i]);
		}
		
		long long ans = sum[n]-cur_sum_right;
		for(int i=0; i<n; i++){
			right.push(nums[2*n-1-i]);
			cur_sum_right+=nums[2*n-1-i]-right.top();
			right.pop();
			ans=std::min(ans, sum[n-1-i]-cur_sum_right);
		}

		return ans;
    }
};

int main(){
	Solution test;
	{
		std::vector<int> nums = {3,1,2};
		assert(-1 == test.minimumDifference(nums));
	}
	{
		std::vector<int> nums = {7,9,5,8,1,3};
		assert(1 == test.minimumDifference(nums));
	}
	return 0;
}