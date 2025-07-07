#include <iostream>
#include <cassert>

class Solution {
	private:
		std::string next_word(std::string& old_word){
			std::string new_word=old_word;
			for(int i=0; i<new_word.size(); i++){
				new_word[i]=(new_word[i]-'a'+1)%26+'a';
			}
			return new_word;
		}
	public:
		char kthCharacter(int k) {
			if(k==1)
				return 'a';
			std::string word="a";
			while(word.size()<k){
				word+=next_word(word);
			}
			return word[k-1];
		}
	};

int main(){
	Solution test;
	assert('b' == test.kthCharacter(5));
	assert('c' == test.kthCharacter(10));
	return 0;
}