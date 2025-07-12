#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cassert>

class Solution {
public:
	int mostBooked(int n, std::vector<std::vector<int>>& meetings) {
		std::sort(meetings.begin(), meetings.end(), 
			[](const std::vector<int>& a, const std::vector<int>& b){
				return a[0] < b[0];
		});

		std::vector<int> rooms_count(n, 0);
		std::priority_queue<int, std::vector<int>, std::greater<int>> free_rooms;
		for (int i = 0; i < n; ++i) {
			free_rooms.push(i);
		}
		std::priority_queue<std::pair<long, int>, std::vector<std::pair<long, int>>, std::greater<>> busy_rooms;

		for (const auto& meeting : meetings) {
			long start = meeting[0], end = meeting[1];

			while (!busy_rooms.empty() && busy_rooms.top().first <= start) {
				free_rooms.push(busy_rooms.top().second);
				busy_rooms.pop();
			}

			if (!free_rooms.empty()) {
				int room = free_rooms.top();
				free_rooms.pop();
				rooms_count[room]++;
				busy_rooms.emplace(end, room);
			} else {
				auto [next_free_time, room] = busy_rooms.top();
				busy_rooms.pop();
				rooms_count[room]++;
				busy_rooms.emplace(next_free_time + (end - start), room);
			}
		}

		return std::distance(rooms_count.begin(), std::max_element(rooms_count.begin(), rooms_count.end()));
	}
};

/*
//its working version too

class Solution {
public:
	int mostBooked(int n, std::vector<std::vector<int>>& meetings) {
		std::sort(meetings.begin(), meetings.end(), 
			[](const std::vector<int>& a, const std::vector<int>& b){
				return a[0] < b[0];
		});

		std::vector<int> rooms_count(n, 0);
		std::priority_queue<int, std::vector<int>, std::greater<int>> free_rooms;
		for (int i = 0; i < n; ++i) {
			free_rooms.push(i);
		}
		std::priority_queue<std::pair<long, int>, std::vector<std::pair<long, int>>, std::greater<>> busy_rooms;

		for (const auto& meeting : meetings) {
			long start = meeting[0], end = meeting[1];

			// Free up rooms that have completed their meetings
			while (!busy_rooms.empty() && busy_rooms.top().first <= start) {
				free_rooms.push(busy_rooms.top().second);
				busy_rooms.pop();
			}

			if (!free_rooms.empty()) {
				// Assign a free room
				int room = free_rooms.top();
				free_rooms.pop();
				rooms_count[room]++;
				busy_rooms.emplace(end, room);
			} else {
				// Reuse the earliest available room
				auto [next_free_time, room] = busy_rooms.top();
				busy_rooms.pop();
				rooms_count[room]++;
				busy_rooms.emplace(next_free_time + (end - start), room);
			}
		}

		// Find the room with the maximum bookings
		return std::distance(rooms_count.begin(), std::max_element(rooms_count.begin(), rooms_count.end()));
	}
};
*/
int main(){
	Solution test;
	{
		int n=2;
		std::vector<std::vector<int>> meetings = {{0,10},{1,5},{2,7},{3,4}};
		assert(0 == test.mostBooked(n, meetings));
	}
	{
		int n=3;
		std::vector<std::vector<int>> meetings = {{1,20},{2,10},{3,5},{4,9},{6,8}};
		assert(1 == test.mostBooked(n, meetings));
	}
	{
		int n=4;
		std::vector<std::vector<int>> meetings = {{18,19},{3,12},{17,19},{2,13},{7,10}};
		assert(0 == test.mostBooked(n, meetings));
	}
	return 0;
}