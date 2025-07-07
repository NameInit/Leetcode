#include <iostream>
#include <vector>

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
	public:
	vector<int> longestCommonPrefix(vector<string> words) {
		int n = words.size();
		if (n <= 2) {
			return vector<int>(n, 0);
		}

		vector<int> adj;
		for (int i = 0; i < n - 1; i++) {
			int j = 0;
			while (j < words[i].size() && j < words[i+1].size() && words[i][j] == words[i+1][j]) {
				j++;
			}
			adj.push_back(j);
		}

		int m = adj.size();
		vector<int> prefix_max(m);
		vector<int> suffix_max(m);

		prefix_max[0] = adj[0];
		for (int i = 1; i < m; i++) {
			prefix_max[i] = max(prefix_max[i-1], adj[i]);
		}

		suffix_max[m-1] = adj[m-1];
		for (int i = m - 2; i >= 0; i--) {
			suffix_max[i] = max(suffix_max[i+1], adj[i]);
		}

		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			int max1 = -1;
			if (i - 2 >= 0) {
				max1 = prefix_max[i-2];
			}

			int max2 = -1;
			if (i + 1 < m) {
				max2 = suffix_max[i+1];
			}

			int new_val = -1;
			if (i >= 1 && i <= n-2) {
				int j = 0;
				while (j < words[i-1].size() && j < words[i+1].size() && words[i-1][j] == words[i+1][j]) {
					j++;
				}
				new_val = j;
			}

			int candidate = max({max1, max2, new_val});
			ans[i] = (candidate == -1) ? 0 : candidate;
		}

		return ans;
	}
};
/*
class Solution {
	private:
		int __len_pref(std::string& word1, std::string& word2){
			int min_size = word1.size()<word2.size() ? word1.size() : word2.size();
			int ans=0;
			for(int i=0; i<min_size; i++){
				if(word1[i]!=word2[i])
					break;
				++ans;
			}
			return ans;
		}
		int __longestCommonPrefix_i(std::vector<std::string>& words, int ind){
			if(words.size()<3)
				return 0;
			if((words.size()==3)&&(ind==1)){
				return __len_pref(words[0],words[2]);
			}
			int ans=0;
			for(int i = 1; i<words.size()-1; i++){
				if(i==ind)
					continue;

				if((i-1)!=ind)
					ans=std::max(ans, __len_pref(words[i], words[i-1]));
				else if((i-2)>=0)
					ans=std::max(ans, __len_pref(words[i], words[i-2]));
				if(((i+1)!=ind))
					ans=std::max(ans, __len_pref(words[i], words[i+1]));
				else if((i+2)<words.size())
					ans=std::max(ans, __len_pref(words[i], words[i+2]));
			}
			return ans;
		}
	public:
		std::vector<int> longestCommonPrefix(std::vector<std::string>& words) {
			if(words.size()==0)
				return std::vector<int>{};
			std::vector<int> ans(words.size());
			std::vector<int> ans(words.size());
			for(int i = 0; i<words.size(); i++){
				ans[i]=0;
				if((i-1)>0)
					ans[i]=std::max(ans[i], __len_pref(words[i], words[i-1]));
				if((i+1)<words.size())
					ans[i]=std::max(ans[i], __len_pref(words[i], words[i+1]));
			}

			// for(int i=0; i<words.size(); i++){
			// 	if(((i-1)>0)&&((i+1)<words.size()))

			// }
			// for(int i = 0; i<words.size(); i++)
			// 	ans.push_back(__longestCommonPrefix_i(words, i));
			return ans;
		}
	};
*/

int main(){
	Solution a;
	// std::string s1="abcd";
	// std::string s2="d";
	std::vector<std::string> v = {"jump","run","run","jump","run"};
	// std::cout << a.__longestCommonPrefix_i(v, 2) << std::endl;
	for(auto it : a.longestCommonPrefix(v))
		std::cout << it << std::endl;
	return 0;
}
/*
Q2. Longest Common Prefix Between Adjacent Strings After Removals
Attempted
Medium
4 pt.
You are given an array of strings words. For each index i in the range [0, words.length - 1], perform the following steps:

Remove the element at index i from the words array.
Compute the length of the longest common prefix among all adjacent pairs in the modified array.
Return an array answer, where answer[i] is the length of the longest common prefix between the adjacent pairs after removing the element at index i. If no adjacent pairs remain or if none share a common prefix, then answer[i] should be 0.

 

Example 1:

Input: words = ["jump","run","run","jump","run"]

Output: [3,0,0,3,3]

Explanation:

Removing index 0:
words becomes ["run", "run", "jump", "run"]
Longest adjacent pair is ["run", "run"] having a common prefix "run" (length 3)
Removing index 1:
words becomes ["jump", "run", "jump", "run"]
No adjacent pairs share a common prefix (length 0)
Removing index 2:
words becomes ["jump", "run", "jump", "run"]
No adjacent pairs share a common prefix (length 0)
Removing index 3:
words becomes ["jump", "run", "run", "run"]
Longest adjacent pair is ["run", "run"] having a common prefix "run" (length 3)
Removing index 4:
words becomes ["jump", "run", "run", "jump"]
Longest adjacent pair is ["run", "run"] having a common prefix "run" (length 3)
Example 2:

Input: words = ["dog","racer","car"]

Output: [0,0,0]

Explanation:

Removing any index results in an answer of 0.
 

Constraints:

1 <= words.length <= 105
1 <= words[i].length <= 104
words[i] consists of lowercase English letters.
The sum of words[i].length is smaller than or equal 105.
*/

/*
class Solution {
	private:
		int __len_pref(std::string& word1, std::string& word2){
			int min_size = word1.size()<word2.size() ? word1.size() : word2.size();
			int ans=0;
			for(int i=0; i<min_size; i++){
				if(word1[i]!=word2[i])
					break;
				++ans;
			}
			return ans;
		}
		int __longestCommonPrefix_i(std::vector<std::string>& words, int ind){
			if(words.size()<3)
				return 0;
            if((words.size()==3)&&(ind==1)){
				return __len_pref(words[0],words[2]);
			}
			int ans=0;
			for(int i = 1; i<words.size()-1; i++){
				if(i==ind)
					continue;

				if((i-1)!=ind)
					ans=std::max(ans, __len_pref(words[i], words[i-1]));
				else if((i-2)>=0)
					ans=std::max(ans, __len_pref(words[i], words[i-2]));
				if(((i+1)!=ind))
					ans=std::max(ans, __len_pref(words[i], words[i+1]));
				else if((i+2)<words.size())
					ans=std::max(ans, __len_pref(words[i], words[i+2]));
			}
			return ans;
		}
	public:
		std::vector<int> longestCommonPrefix(std::vector<std::string>& words) {
			if(words.size()==0)
				return std::vector<int>{};
			std::vector<int> ans{};
			for(int i = 0; i<words.size(); i++)
				ans.push_back(__longestCommonPrefix_i(words, i));
			return ans;
		}
	};©leetcode
*/