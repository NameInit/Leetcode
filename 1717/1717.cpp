#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
	int maximumGain(std::string s, int x, int y) {
		int ans = 0;
		if (x < y) {
			std::swap(x, y);
			for (auto &c : s) {
				if (c == 'a') c = 'b';
				else if (c == 'b') c = 'a';
			}
		}
		
		std::stack<char> st;
		for (const auto c : s) {
			if (!st.empty() && st.top() == 'a' && c == 'b') {
				st.pop();
				ans += x;
			} else {
				st.push(c);
			}
		}

		std::string rem;
		while (!st.empty()) {
			rem += st.top();
			st.pop();
		}
		std::reverse(rem.begin(), rem.end());
		for (char c : rem) {
			if (!st.empty() && st.top() == 'b' && c == 'a') {
				st.pop();
				ans += y;
			} else {
				st.push(c);
			}
		}

		return ans;
	}
};

int main(){
	Solution test;
	// test.maximumGain("cdbcbbaaabab",4,5); //19
	test.maximumGain("aabbaaxybbaabb",5,4); //20
	return 0;
}