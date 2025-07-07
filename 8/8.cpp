#include <iostream>
#include <cassert>
#include <cstdint>


class Solution {
public:
	int myAtoi(std::string s) {
		if(s.size()==0)
			return {};

		int shift = 0;
		for(int i=0; i<s.size(); i++){
			if(s[i]==' '){
				shift+=1;
			}
			else{
				break;
			}
		}

		int sign = s[shift]=='-' ? -1 : 1;
		int flag_num=0;
		long int ans=0;
		for(int i=shift+((s[shift]=='-')||(s[shift]=='+')); i<s.size(); i++){
			if((s[i]>='0')&&(s[i]<='9')){
				ans=ans*10+(s[i]-'0');
			}
			else{
				break;
			}

			if(ans>INT32_MAX)
				return sign==1 ? INT32_MAX : INT32_MIN;
			
		}

		return ans*sign;
	}
};

int main(){
	Solution test;
	assert(42 == test.myAtoi("42"));
	assert(-42 == test.myAtoi("-042"));
	assert(1337 == test.myAtoi("1337c0d3"));
	assert(0 == test.myAtoi("0-1"));
	assert(0 == test.myAtoi("words and 987"));
	assert(-42 == test.myAtoi("   -042"));
	assert(1 == test.myAtoi("+1"));
	return 0;
}