#include <iostream>
#include <cassert>


class Solution {
public:
	std::string longestPalindrome(std::string s) {
		int ans_pos=0;
		int ans_len=1;
		for(int i=0; i<s.size(); i++){
			int j=0;
			while(((i+j)<s.size())&&((i-j)>=0)&&(s[i+j]==s[i-j])){
				if(ans_len<(2*j+1)){
					ans_len=2*j+1;
					ans_pos=i-j;
				}
				j++;
			}

			j=0;
			while(((i+j)<s.size())&&((i-j-1)>=0)&&(s[i+j]==s[i-j-1])){
				if(ans_len<(2*(j+1))){
					ans_len=2*(j+1);
					ans_pos=i-j-1;
				}
				j++;
			}
		}
		
		return s.substr(ans_pos, ans_len);
	}
};

int main(){
	Solution test;
	{
		std::string s="babad";
		assert("bab" == test.longestPalindrome(s));
	}
	{
		std::string s="cbbd";
		assert("bb" == test.longestPalindrome(s));
	}
	return 0;
}