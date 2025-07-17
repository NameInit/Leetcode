#include <iostream>
#include <vector>
#include <cassert>


class Solution {
public:
    int maximumLength(std::vector<int>& nums, int k) {
		std::vector<std::vector<int>> ans(k,std::vector<int>(k,0));
		int res=0;
		for(const auto &num : nums){
            int ost = num%k;
			for(int i=0; i<k; ++i){
				ans[i][ost]=ans[i][(k-ost+i)%k]+1;
				if(ans[i][ost]>res){
					res=ans[i][ost];
				}
			}
		}
		return res;
    }
};

int main(){
	Solution test;
	{
		int k=2;
		std::vector<int> nums={1,2,3,4,5};
		assert(5 == test.maximumLength(nums,k));
	}
	{
		int k=3;
		std::vector<int> nums={1,4,2,3,1,4};
		assert(4 == test.maximumLength(nums,k));
	}
	return 0;
}