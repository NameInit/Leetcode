#include <iostream>
#include <vector>
#include <array>
#include <cassert>


class Solution {
public:
	int findLucky(std::vector<int>& arr) {
		std::array<int, 501> counter{};
		for(auto item : arr)
			++counter[item];
		
		for(int i=500; i>0; i--)
			if(counter[i]==i)
				return i;
		return -1;
	}
};

int main(){
	Solution test;
	{
		std::vector<int> v{2,2,3,4};
		assert(2 == test.findLucky(v));
	}
	{
		std::vector<int> v{1,2,2,3,3,3};
		assert(3 == test.findLucky(v));
	}
	{
		std::vector<int> v{2,2,2,3,3};
		assert(-1 == test.findLucky(v));
	}
	return 0;
}