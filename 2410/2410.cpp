#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>

//O(nlogn+klogk)
class Solution {
public:
    int matchPlayersAndTrainers(std::vector<int>& players, std::vector<int>& trainers) {
        std::sort(players.begin(), players.end());
		std::sort(trainers.begin(), trainers.end());

		int i=0,j=0;
		int n = players.size(), k=trainers.size();
		while((i<n)&&(j<k)){
			if(players[i]<=trainers[j]){
				++i;
				++j;
			}
			else{
				++j;
			}
		}

		return i;
    }
};

/*
//Its working version too, but its slowly for leetcode, at the same time O(k*logk+n*logk)

class Solution {
public:
    int matchPlayersAndTrainers(std::vector<int>& players, std::vector<int>& trainers) {
        std::multiset<int> temp_trainers(trainers.begin(), trainers.end());
		int ans=0;
		for(auto player : players){
			auto it_temp_trainers = std::lower_bound(temp_trainers.begin(), temp_trainers.end(),player);
			if(it_temp_trainers!=temp_trainers.end()){
				++ans;
				temp_trainers.erase(it_temp_trainers);
			}
			if(temp_trainers.size()==0){
				break;
			}
		}
		return ans;
    }
};
*/

int main(){
	Solution test;
	{
		std::vector<int> players = {4,7,9};
		std::vector<int> trainers = {8,2,5,8};
		assert(2 == test.matchPlayersAndTrainers(players, trainers));
	}
	{
		std::vector<int> players = {1,1,1};
		std::vector<int> trainers = {10};
		assert(1 == test.matchPlayersAndTrainers(players, trainers));
	}
	{
		std::vector<int> players = {2,1};
		std::vector<int> trainers = {2,2};
		assert(2 == test.matchPlayersAndTrainers(players, trainers));
	}
	return 0;
}