#include <iostream>
#include <vector>
#include <cassert>


class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left=0, right=height.size()-1;
		int ans=(right-left)*std::min(height[left], height[right]);
		while((right-left)>1){
			height[left]>height[right] ? --right : ++left;
			ans=std::max(ans,(right-left)*std::min(height[left], height[right]));
		}
		return ans;
    }
};

int main(){
	Solution test;
	{
		std::vector<int> height = {1,8,6,2,5,4,8,3,7};
		assert(49==test.maxArea(height));
	}
	{
		std::vector<int> height = {1,1};
		assert(1==test.maxArea(height));
	}
	return 0;
}