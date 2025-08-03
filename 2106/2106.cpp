#include <iostream>
#include <vector>
#include <cassert>


class Solution {
public:
    int maxTotalFruits(std::vector<std::vector<int>>& fruits, int startPos, int k) {
        int i = 0, j = 0;
        int n = fruits.size();
        int sum = 0;
        int ans = 0;

        for (j = 0; j < n; j++) {
            sum += fruits[j][1];
            
            while (i <= j) {
                int L = fruits[i][0];
                int R = fruits[j][0];
                int current_cost;
                
                if (R <= startPos) {
                    current_cost = startPos - L;
                } else if (L >= startPos) {
                    current_cost = R - startPos;
                } else {
                    current_cost = std::min(startPos - 2*L + R, 2*R - startPos - L);
                }
                
                if (current_cost <= k) {
                    break;
                }
                
                sum -= fruits[i][1];
                i++;
            }
            
            if (i <= j) {
                ans = std::max(ans, sum);
            }
        }
        
        return ans;
    }
};

/*
need refactoring

class Solution {
public:
    int maxTotalFruits(std::vector<std::vector<int>>& fruits, int startPos, int k) {
        int right_sum=0, ind_last_right, ind_first_right=-1;
		for(int i=0; i<fruits.size(); ++i){
			if((fruits[i][0]>=startPos)&&(fruits[i][0]<=(startPos+k))){
				right_sum+=fruits[i][1];
				ind_last_right=i;
				if(ind_first_right==-1)
					ind_first_right=i;
			}
			else if(fruits[i][0]>(startPos+k))
				break;
		}

		if(ind_first_right==-1){
			int left_sum=0;
			for(int i=fruits.size()-1; (i>=0)&&((startPos-fruits[i][0])<=k); --i){
				left_sum+=fruits[i][1];
			}
			return left_sum;
		}

		if(ind_first_right==0){
			return right_sum;
		}
		
		int ans=right_sum;
		int temp_ans=right_sum;
		for(int i=ind_first_right-1; (i>=0)&&((startPos-fruits[i][0])<=k); --i){
			temp_ans+=fruits[i][1];
			while((fruits[ind_last_right][0]-fruits[i][0])>(k-(startPos-fruits[i][0]))){
				temp_ans-=fruits[ind_last_right][1];
				--ind_last_right;
			}
			if(temp_ans>ans)
				ans=temp_ans;
		}

		return ans;
    }
};
*/

int main(){
	Solution test;
	{
		std::vector<std::vector<int>> fruits = {{2,8},{6,3},{8,6}};
		int startPos=5;
		int k=4;
		assert(9 == test.maxTotalFruits(fruits,startPos,k));
	}
	{
		std::vector<std::vector<int>> fruits = {{0,9},{4,1},{5,7},{6,2},{7,4},{10,9}};
		int startPos=5;
		int k=4;
		assert(14 == test.maxTotalFruits(fruits,startPos,k));
	}
	{
		std::vector<std::vector<int>> fruits = {{0,3},{6,4},{8,5}};
		int startPos=3;
		int k=2;
		assert(0 == test.maxTotalFruits(fruits,startPos,k));
	}
	return 0;
}