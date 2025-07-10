#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
	int maxFreeTime(int eventTime, std::vector<int>& startTime, std::vector<int>& endTime) {
		int n = startTime.size();
		std::vector<int> d(n, 0);
		int left=0, right=0;
		for(int i=0; i<n; i++){
			left=std::max(left, ((i-1)<0 ? 0 : startTime[i-1])-((i-2)<0 ? 0 : endTime[i-2]));
			right=std::max(right, (((n-1-i)+2)>=n ? eventTime : startTime[(n-1-i)+2])-(((n-1-i)+1)>=n ? eventTime : endTime[(n-1-i)+1]));
			d[i]=std::max(d[i], left);
			d[(n-1-i)]=std::max(d[(n-1-i)], right);
		}

		int ans=0;
		for(int i=0; i<n; i++){
			int duration_event = endTime[i]-startTime[i];
			int sum_distance_to_neigh_event = (startTime[i]-((i-1)<0 ? 0 : endTime[i-1]))
			+(((i+1)>=n ? eventTime : startTime[i+1])-endTime[i]);

			
			ans=std::max(ans, sum_distance_to_neigh_event);
			if(duration_event<=d[i]){
				ans=std::max(ans, sum_distance_to_neigh_event+duration_event);
			}
		}
		return ans;
	}
};

int main(){
	Solution test;
	{
		int eventTime = 5;
		std::vector<int> startTime = {1,3};
		std::vector<int> endTime = {2,5};
		assert(2 == test.maxFreeTime(eventTime, startTime, endTime));
	}
	{
		int eventTime = 10;
		std::vector<int> startTime = {0,7,9};
		std::vector<int> endTime = {1,8,10};
		assert(7 == test.maxFreeTime(eventTime, startTime, endTime));
	}
	{
		int eventTime = 10;
		std::vector<int> startTime = {0,3,7,9};
		std::vector<int> endTime = {1,4,8,10};
		assert(6 == test.maxFreeTime(eventTime, startTime, endTime));
	}
	{
		int eventTime = 5;
		std::vector<int> startTime = {0,1,2,3,4};
		std::vector<int> endTime = {1,2,3,4,5};
		assert(0 == test.maxFreeTime(eventTime, startTime, endTime));
	}
	return 0;
}