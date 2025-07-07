#include <iostream>
#include <cstring>
#include <array>
#include <cassert>
#include <numeric>

class Solution {
public:
	int possibleStringCount(std::string word) {
		if(word.size()==0)
			return 0;
		if(word.size()==1)
			return 1;

		std::array<int, 100> letter_count{};
		int cur_index=0;
		char last_letter = 0;

		for(auto letter : word){
			if(last_letter==0);
			else if(last_letter==letter)
				++letter_count[cur_index];
			else
				++cur_index;
			last_letter=letter;
		}
		
		return std::accumulate(letter_count.begin(), letter_count.end(), 0)+1;
	}
};


int main(){
	Solution test;
	assert(4 == test.possibleStringCount(static_cast<std::string>("aaaa")));
	assert(5 == test.possibleStringCount(static_cast<std::string>("abbcccc")));
	assert(1 == test.possibleStringCount(static_cast<std::string>("abcd")));
	assert(2 == test.possibleStringCount(static_cast<std::string>("all")));
	assert(5 == test.possibleStringCount(static_cast<std::string>("aaabbb")));
	assert(1 == test.possibleStringCount(static_cast<std::string>("ere")));
	return 0;
}