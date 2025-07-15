#include <iostream>
#include <bitset>
#include <cassert>


class Solution {
public:
    bool isValid(std::string word) {
		if(word.size()<3){
			return false;
		}

		std::bitset<2> flags; //[0] - vowel; [1] - consonant
		for(auto letter : word){
			if(((letter<'0')||(letter>'9'))&&((letter<'a')||(letter>'z'))&&((letter<'A')||(letter>'Z'))){
				return false;
			}
			if((letter == 'a')||(letter == 'e')||(letter == 'i')||(letter == 'o')||(letter == 'u')||
				(letter == 'A')||(letter == 'E')||(letter == 'I')||(letter == 'O')||(letter == 'U')){
				flags[0]=1;
			}
			else if((letter<'0')||(letter>'9')){
				flags[1]=1;
			}
		}
        return flags.count()==2;
    }
};

int main(){
	Solution test;
	assert(true == test.isValid(static_cast<std::string>("234Adas")));
	assert(false == test.isValid(static_cast<std::string>("b3")));
	assert(false == test.isValid(static_cast<std::string>("a3$e")));
	return 0;
}