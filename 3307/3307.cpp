#include <iostream>
#include <vector>
#include <cassert>
#include <cstdint>
#include <bitset>

class Solution {
public:
	char kthCharacter(long long k, std::vector<int>& operations){
		if(k==0)
			return 0;
		if(k==1)
			return 'a';

		k-=1;
		int shift=0;
		for(auto item : operations){
			shift+=item&(k%2);
			k/=2;
			if(k==0)
				return 'a'+shift%26;
		}
		return 'a'+shift%26;
	}
};

/*
class Solution {
private:
	uint64_t bpow(uint64_t osn, uint64_t st){
		if(st==0)
			return 1;
		if(st==1)
			return osn;
		if(st%2==0){
			return bpow(osn*osn, st/2);
		}
		return bpow(osn, st-1)*osn;
	}
public:
	char kthCharacter(long long k, std::vector<int>& operations) {
		if(k==0)
			return 0;
		if(k==1)
			return 'a';
		uint64_t shift = 0;
		uint64_t operations_size = operations.size();
		uint64_t temp_k=static_cast<uint64_t>(k);
		uint64_t word_size = bpow(2, operations.size());
		
		for(long long i=0; i<operations_size; i++){
			if(temp_k<=(word_size/2)){
				word_size/=2;
			}
			else if(operations[operations_size-1-i]==0){
				temp_k-=word_size/2;
				word_size/=2;
			}
			else{
				shift+=1;
				temp_k-=word_size/2;
				word_size/=2;
			}
		}

		return 'a'+shift%26;
	}
};
*/

/*
class Solution {
private:
	std::string next_word(std::string& old_word){
		std::string new_word=old_word;
		for(long long i=0; i<new_word.size(); i++){
			new_word[i]=(new_word[i]-'a'+1)%26+'a';
		}
		return new_word;
	}
public:
	char kthCharacter(long long k, std::vector<long long>& operations) {
		if(k==0)
			return 0;
		if(k==1)
			return 'a';

		std::string word = "a";

		long long i=0;
		for(auto option : operations){
			if(option)
				word+=next_word(word);
			else
				word+=word;
			if(k<=word.size())
				return word[k-1];
		}
		return 0;
	}
};
*/

int main(){
	Solution test;

	{
		std::vector<int> operations={0,0,0};
		assert('a' == test.kthCharacter(5, operations));
	}
	{
		std::vector<int> operations={0,1,0,1};
		assert('b' == test.kthCharacter(10, operations));
	}
	return 0;
}