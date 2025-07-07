#include <iostream>
#include <cassert>
#include <cstdbool>
#include <cstdint>


class Solution {
public:
	bool isPalindrome(int x) {
		if(x<0)
			return false;
		if(x<10)
			return true;
		
		long int temp_x=0;
		int copy_x=x;
		while(x>0){
			temp_x=temp_x*10+x%10;
			if(temp_x>INT32_MAX)
				return false;
			x/=10;
		}
			
		return static_cast<bool>(temp_x==copy_x);
	}
};

int main(){
	Solution test;
	assert(test.isPalindrome(121));
	assert(!test.isPalindrome(-121));
	assert(!test.isPalindrome(10));
	assert(!test.isPalindrome(1234567899));
	return 0;
}