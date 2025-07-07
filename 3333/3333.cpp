#include <iostream>
#include <cassert>
#include <vector>
#include <cstdint>

class Solution {
	public:
		int possibleStringCount(std::string word, int k) {
			const int mod = 1000000007;
			std::vector<int> runs;
			int n = word.size();
			for (int i = 0; i < n; ) {
				int j = i;
				while (j < n && word[j] == word[i]) {
					j++;
				}
				runs.push_back(j - i);
				i = j;
			}
	
			int m = runs.size();
			long total_ways = 1;
			for (int r : runs) {
				total_ways = (total_ways * r) % mod;
			}
	
			if (m >= k) {
				return total_ways;
			}
	
			std::vector<long> dp(k, 0);
			dp[0] = 1;
	
			for (int r_i : runs) {
				std::vector<long> next_dp(k, 0);
				long window_sum = 0;
				int left_bound = 0;
	
				for (int j = 1; j < k; j++) {
					window_sum = (window_sum + dp[j-1]) % mod;
					int L_bound = (j - r_i) < 0 ? 0 : (j - r_i);
					while (left_bound < L_bound) {
						window_sum = (window_sum - dp[left_bound] + mod) % mod;
						left_bound++;
					}
					next_dp[j] = window_sum;
				}
				dp = next_dp;
			}
	
			long ways_below_k = 0;
			for (int j = 0; j < k; j++) {
				ways_below_k = (ways_below_k + dp[j]) % mod;
			}
	
			long ans = (total_ways - ways_below_k + mod) % mod;
			return (int)ans;
		}
	};

/*
class Solution {
public:
	int fact(int n){
		if((n==0) || (n==1))
			return 1;
		int ans=1;
		for(int i=2; i<=n; ++i)
			ans*=i;
		return ans;
	}

	int c_n_k(int n, int k){
		return 0;
	}
public:
	int possibleStringCount(std::string word, int k) {
		if(k>word.size())
			return 0;
		if(k==word.size())
			return 1;
		char last_letter=0;
		int temp_count=0;
		int sum_count_repeat=0;
		int count_segments=0;
		std::vector<int> count_repeat{};

		for(auto letter : word){
			if(last_letter==0);
			else if(letter==last_letter){
				++temp_count;
				++sum_count_repeat;
			}
			else if(temp_count!=0){
				count_repeat.push_back(temp_count);
				temp_count=0;
				++count_segments;
			}
			last_letter=letter;
		}

		if(temp_count!=0){
			count_repeat.push_back(temp_count);
			++count_segments;
		}
		
		std::cout << "COUNT_REPEAT="<<sum_count_repeat << std::endl;
		std::cout << "COUNT_SEGMENTS="<<count_segments << std::endl;
		for(auto count : count_repeat){
			std::cout << count << ' ';
		}
		std::cout << std::endl;

		uint64_t ans=1;
		uint64_t last_add=1;
		int word_size=word.size();
		int temp_segments = count_segments;

		for(int temp_k=word_size-1; temp_k>=k; --temp_k){
			last_add*=static_cast<uint64_t>(temp_segments/(word_size-temp_k));
			ans+=last_add;
			--temp_segments;
		}

		std::cout << "ANS: " << ans << std::endl;

		return ans%static_cast<uint64_t>(10e9+7);
	}
};
*/
int main(){
	Solution test;
	assert(5 == test.possibleStringCount(static_cast<std::string>("aabbccdd"), 7));
	assert(1 == test.possibleStringCount(static_cast<std::string>("aabbccdd"), 8));
	assert(8 == test.possibleStringCount(static_cast<std::string>("aaabbb"), 3));
	assert(15 == test.possibleStringCount(static_cast<std::string>("aabbccdd"), 5));
	return 0;
}