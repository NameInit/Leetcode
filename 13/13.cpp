#include <iostream>
#include <unordered_map>
#include <cassert>


class Solution {
public:
    int romanToInt(std::string s) {
		std::unordered_map<char, int> letter_weight = { {'I', 1},
														{'V', 5},
														{'X', 10},
														{'L', 50},
														{'C', 100},
														{'D', 500},
														{'M', 1000}};
        
		int n = s.size();
		char prev = s[n-1];
		int ans=letter_weight[prev];
		int znak=1;

		for(int i=n-2; i>=0; --i){
			if(letter_weight[s[i]]<letter_weight[prev]){
				znak=-1;
			}
			else if(letter_weight[s[i]]>letter_weight[prev]){
				znak=1;
			}
			ans+=znak*letter_weight[s[i]];
			prev=s[i];
		}

		return ans;
    }
};

int main(){
	Solution test;
	assert(3 == test.romanToInt("III"));
	assert(58 == test.romanToInt("LVIII"));
	assert(1994 == test.romanToInt("MCMXCIV"));
	return 0;
}