class Solution {
	public:
		int maxEvents(std::vector<std::vector<int>>& events) {
			if (events.empty()) return 0;
			
			std::sort(events.begin(), events.end());
			std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
			int count = 0;
			int i = 0;
			int n = events.size();
			int max_day = 0;
			
			for (const auto& event : events) {
				if (event[1] > max_day) {
					max_day = event[1];
				}
			}
			
			for (int d = 1; d <= max_day; d++) {
				while (i < n && events[i][0] == d) {
					pq.push(events[i][1]);
					i++;
				}
				
				while (!pq.empty() && pq.top() < d) {
					pq.pop();
				}
				
				if (!pq.empty()) {
					pq.pop();
					count++;
				}
			}
			
			return count;
		}
	};