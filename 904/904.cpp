#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>


class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        std::unordered_map<int, int> freq;
        int left = 0;
        int maxFruits = 0;

        for (int right = 0; right < fruits.size(); ++right) {
            freq[fruits[right]]++;
            
            while (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }
                left++;
            }
            
            maxFruits = std::max(maxFruits, right - left + 1);
        }
        
        return maxFruits;
    }
};

int main(){
	Solution test;
	{
		std::vector<int> fruits={1,2,1};
		assert(3 == test.totalFruit(fruits));
	}
	{
		std::vector<int> fruits={0, 1, 2, 2};
		assert(3 == test.totalFruit(fruits));
	}
	{
		std::vector<int> fruits={1, 2, 3, 2 , 2};
		assert(4 == test.totalFruit(fruits));
	}
	return 0;
}