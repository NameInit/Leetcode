#include <iostream>
#include <cmath>
#include <cstdint>
#include <cassert>


class Solution {
public:
	int reverse(int x) {
		if((x>-10)&&(x<10))
			return x;
		
		long int sign = x<0 ? -1 : 1; x*=sign;
		long int ans=0;

		while(x>0){
			ans=ans*10+x%10;
			if(ans>INT32_MAX)
				return 0;
			x/=10;
		}

		return ans*sign;
	}
};
/*
class Solution {
private:
	int len_number(int positive_number){
		if(positive_number<10)
			return 1;
		
		int res=0;
		while(positive_number>0){
			positive_number/=10;
			++res;
		}
		return res;
	}

	int get_digit(int positive_number, int pos){
		return positive_number%(static_cast<int>(std::pow(10, pos)))/(static_cast<int>(std::pow(10, (pos-1))));
	}

public:
	int reverse(int x) {
		if((x>-10)&&(x<10))
			return x;
		
		int sign = x<0 ? -1 : 1;
		x=x*sign;
		int len_num = len_number(x);

		for(int i=0; i<len_num/2; i++){
			int left_digit = get_digit(x, i+1);
			int right_digit = get_digit(x, len_num-i);
			x+=(right_digit-left_digit)*static_cast<int>(std::pow(10, i));
			x+=(left_digit-right_digit)*static_cast<int>(std::pow(10, len_num-i-1));
		}

		return x*sign;
	}
};
*/

int main(){
	Solution test;
	assert(-21 == test.reverse(-12));
	assert(321 == test.reverse(123));
	assert(-321 == test.reverse(-123));
	assert(21 == test.reverse(120));
	assert(0 == test.reverse(1534236469));
	return 0;
}