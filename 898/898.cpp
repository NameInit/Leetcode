#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

class Solution {
public:
	int subarrayBitwiseORs(std::vector<int>& arr) {
		std::unordered_set<int> unique, temp_ps, ps;
		for (const int &num : arr) {
			ps.clear();
			ps.emplace(num);
			for (const int &elem : temp_ps) {
				ps.emplace(elem | num);
			}
			unique.insert(ps.begin(), ps.end());
			temp_ps.swap(ps);
		}
		return unique.size();
	}
};

// class Solution {
// public:
//     int subarrayBitwiseORs(std::vector<int>& arr) {
//         std::unordered_set<int> unique;
// 		std::unordered_set<int> ps;
// 		for(const auto &item : arr){
// 			std::unordered_set<int> temp_ps;
// 			for(const auto &elem : ps){
// 				temp_ps.emplace(elem | item);
// 			}
// 			temp_ps.emplace(item);
// 			ps=std::move(temp_ps);
// 			for(const auto &elem : ps){
// 				unique.emplace(elem);
// 			}
// 		}
// 		return unique.size();
//     }
// };

// class Solution {
// public:
//     int subarrayBitwiseORs(std::vector<int>& arr) {
//         std::unordered_set<int> unique;
// 		int max_num = 0, n = arr.size();
// 		for(const auto &item : arr){
// 			max_num|=item;
// 		}

// 		unique.insert(max_num);

// 		for(int i=0; (i<n)&&(max_num!=0); ++i){
// 			int temp_num=0;
// 			for(int j=i; (j<n)&&(temp_num!=max_num); ++j){
// 				temp_num|=arr[j];
// 				unique.insert(temp_num);
// 			}
// 		}
// 		return unique.size();
//     }
// };

int main(){
	Solution test;
	{
		std::vector<int> arr={0};
		std::cout << test.subarrayBitwiseORs(arr) << std::endl;
	}
	{
		std::vector<int> arr={1,1,2};
		std::cout << test.subarrayBitwiseORs(arr) << std::endl;
	}
	{
		std::vector<int> arr={1,2,4};
		std::cout << test.subarrayBitwiseORs(arr) << std::endl;
	}
	return 0;
}