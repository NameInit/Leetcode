#include <iostream>
#include <cassert>


class Solution {
public:
	std::string convert(std::string s, int numRows) {
		if(s.size()==0)
			return {};
		if((s.size()<=numRows) || (numRows==1))
			return s;

		int count_letter_in_block = 2*numRows-2;
		std::string ans{};

		for(int i=0; i<numRows; i++){
			int shift = 2*i;
			for(int j=0; (i+j)<s.size(); j+=shift){
				ans+=s[i+j];
				if((count_letter_in_block-shift)!=0){
					shift=count_letter_in_block-shift;
				}
			}
		}
		return ans;
	}
};

int main(){
	Solution test;
	{
		std::string s="PAYPALISHIRING";
		assert("PAHNAPLSIIGYIR" == test.convert(s, 3));
	}
	{
		std::string s="PAYPALISHIRING";
		assert("PINALSIGYAHRPI" == test.convert(s, 4));
	}
	{
		std::string s="PAYPALISHIRING";
		assert("PHASIYIRPLIGAN" == test.convert(s, 5));
	}
	return 0;
}