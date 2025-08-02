#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <cstdint>
#include <cassert>


/*
a dubious task, since:
for data: basket1 = {4,2,2}, basket2 = {1,1,2}
wait result -1, but if swap basket1[0] and basket2[2],
basket1 and basket2 will have an equal amount
*/

class Solution {
public:
    long long minCost(std::vector<int>& basket1, std::vector<int>& basket2) {
        int m = INT32_MAX;
        std::unordered_map<int, int> frequency_map;
        for (int b1 : basket1) {
            frequency_map[b1]++;
            m = std::min(m, b1);
        }
        for (int b2 : basket2) {
            frequency_map[b2]--;
            m = std::min(m, b2);
        }
        std::vector<int> merge;
        for (auto [k, c] : frequency_map) {
            if (c % 2 != 0) {
                return -1;
            }
            for (int i = 0; i < abs(c) / 2; ++i) {
                merge.push_back(k);
            }
        }
        std::nth_element(merge.begin(), merge.begin() + merge.size() / 2,
                    merge.end());
        return std::accumulate(merge.begin(), merge.begin() + merge.size() / 2, 0ll,
                          [&](long long res, int x) -> long long {
                              return res + std::min(2 * m, x);
                          });
    }
};

int main(){
	Solution test;
	{
		std::vector<int> basket1 = {4,2,2,2}, basket2 = {1,4,1,2};
		assert(1==test.minCost(basket1,basket2));
	}
	{
		std::vector<int> basket1 = {2,3,4,1}, basket2 = {3,2,5,1};
		assert(-1==test.minCost(basket1,basket2));
	}
	return 0;
}