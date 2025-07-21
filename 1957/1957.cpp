#include <iostream>
#include <cassert>


class Solution {
public:
    std::string makeFancyString(std::string s) {
        if(s.size()<3){
			return s;
		}
		int new_len = 2;
		int old_len=s.size();
		for(int i=2; i<old_len; i++){
			if((s[i]!=s[new_len-1])||(s[i]!=s[new_len-2])){
				s[new_len]=s[i];
				++new_len;
			}
		}
		s.resize(new_len);
		return s;
    }
};

int main(){
	Solution test;
	std::string a;
	
	assert(test.makeFancyString("leeetcode") == "leetcode");
	assert(test.makeFancyString("aaabaaaa") == "aabaa");
	assert(test.makeFancyString("aab") == "aab");
	return 0;
}