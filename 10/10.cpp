#include <iostream>
#include <vector>
#include <cassert>

/*
class Solution {
public:
    bool isMatch(std::string s, std::string p) {
		int n=s.size(), m=p.size();
		int i=n-1, j=m-1;
		int flag_star=0, flag_point=0;
		int last_ind_star=m-1;
		while((i>=0)&&(j>=0)){
			if(p[j]=='*'){
				flag_star=1;
				last_ind_star=i;
				--j;
			}
			if(flag_star==0){
				if((p[j]==s[i])||(p[j]=='.')){
					--i;
					--j;
				}
				else{
					return false;
				}
			}
			else{
				while(((p[j]==s[i])||(p[j]=='.'))&&(i>=0)){
					--i;
				}
				--j;
				if((i<0)&&(j<0)){
					break;
				}
				while((p[j]!=s[i])&&(p[j]!='.')&&(i<(last_ind_star-1))){
					i++;
				}
				if(i==(last_ind_star-1)){
					return false;
				}
			}
		}
		return (i<0)&&(j<0) ? true : false;
    }
};
*/

class Solution {
public:
	bool isMatch(std::string s, std::string p) {
		int n = s.size(), m = p.size();
		std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));
		dp[0][0] = true;
		for (int j = 1; j <= m; ++j) {
			if (p[j - 1] == '*' && j >= 2) {
				dp[0][j] = dp[0][j - 2];
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				} else if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 2];
					if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
						dp[i][j] = dp[i][j] || dp[i - 1][j];
					}
				}
			}
		}
		return dp[n][m];
	}
};

int main(){
	Solution test;
	{
		std::string s = "aa";
		std::string p = "a";
		assert(false == test.isMatch(s,p));
	}
	{
		std::string s = "aa";
		std::string p = "a*";
		assert(true == test.isMatch(s,p));
	}
	{
		std::string s = "ab";
		std::string p = ".*";
		assert(true == test.isMatch(s,p));
	}
	return 0;
}