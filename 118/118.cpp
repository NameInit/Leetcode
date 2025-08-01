#include <iostream>
#include <vector>


class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ans(numRows);
		ans[0]={1};
		for(int i=1; i<numRows; ++i){
			ans[i]=ans[i-1];
			for(int j=ans[i].size()-1; j>0; --j){
				ans[i][j]+=ans[i][j-1];
			}
			ans[i].push_back(ans[i][0]);
		}
		return ans;
    }
};

// class Solution {
// public:
//     std::vector<std::vector<int>> generate(int numRows) {
//         std::vector<std::vector<int>> ans={{1}};
		
// 		for(int i=2; i<=numRows; ++i){
// 			std::vector<int> new_item(ans[ans.size()-1].begin(),ans[ans.size()-1].end());
			
// 			for(int j=new_item.size()-1; j>0; --j){
// 				new_item[j]+=new_item[j-1];
// 			}

// 			new_item.push_back(ans[ans.size()-1][0]);
// 			ans.push_back(new_item);
// 		}
// 		return ans;
//     }
// };

int main(){
	Solution test;
	test.generate(5);//{{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}}
	test.generate(1);//{{1}}
	return 0;
}