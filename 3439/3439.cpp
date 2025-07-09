#include <iostream>
#include <vector>


class Solution {
public:
	int maxFreeTime(int eventTime, int k, std::vector<int>& startTime, std::vector<int>& endTime) {
		int temp_ans=0;
		int ans=0;
		for(int i=0; i<(k+1); i++){
			temp_ans+=(i<startTime.size() ? startTime[i] : eventTime)-((i-1)<0 ? 0 : endTime[i-1]);
		}
		
		ans=temp_ans;

		for(int i=1; i<(startTime.size()-k+1); i++){
			temp_ans+=(((i+k)>=startTime.size() ? eventTime : startTime[i+k])-endTime[i+k-1])-(startTime[i-1]-((i-2)<0 ? 0 : endTime[i-2]));
			ans=std::max(ans, temp_ans);
		}
		return ans;
	}
};

int main(){
	Solution test;
	{
		int eventTime = 5;
		int k = 1;
		std::vector<int> startTime = {1,3};
		std::vector<int> endTime = {2,5};
		std::cout << "TEST 1:"<<std::endl;
		test.maxFreeTime(eventTime,k,startTime,endTime);
		std::cout << std::endl; 
	}
	{
		int eventTime = 10;
		int k = 1;
		std::vector<int> startTime = {0,2,9};
		std::vector<int> endTime = {1,4,10};
		std::cout << "TEST 2:"<<std::endl;
		test.maxFreeTime(eventTime,k,startTime,endTime);
		std::cout << std::endl; 
	}
	{
		int eventTime = 5;
		int k = 2;
		std::vector<int> startTime = {0,1,2,3,4};
		std::vector<int> endTime = {1,2,3,4,5};
		std::cout << "TEST 3:"<<std::endl;
		test.maxFreeTime(eventTime,k,startTime,endTime);
		std::cout << std::endl; 
	}
	return 0;
}