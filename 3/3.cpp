#include <iostream>
#include <unordered_set>
#include <cassert>

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(128, -1);
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (charIndex[c] >= left) {
                left = charIndex[c] + 1;
            }
            charIndex[c] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

/*
class Solution {
	public:
		int lengthOfLongestSubstring(std::string s) {
			if(s.size()==0)
				return 0;
			if(s.size()==1)
				return 1;
			
			std::unordered_set<char> unique;
			int ind_begin=0;
			int ind_end=0;
			int ans=1;
			while(ind_end!=s.size()){
				if(unique.find(s[ind_end])==unique.end()){
					unique.insert(s[ind_end]);
					++ind_end;
					ans=std::max(ans, ind_end-ind_begin);
				}
				else{
					unique.erase(unique.find(s[ind_begin]));
					++ind_begin;
				}
			}
			return ans;
		}
	};
*/

int main(){
	Solution test;
	assert(3 == test.lengthOfLongestSubstring(static_cast<std::string>("abcabcbb")));
	assert(1 == test.lengthOfLongestSubstring(static_cast<std::string>("bbbbb")));
	assert(3 == test.lengthOfLongestSubstring(static_cast<std::string>("pwwkew")));
	return 0;
}