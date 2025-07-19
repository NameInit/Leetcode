#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cassert>


class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
		std::sort(folder.begin(), folder.end(), [](const std::string &a, const std::string &b){ return a.size()<b.size(); });
		std::unordered_set<std::string> root_folder{};

		for(auto &str : folder){
			std::string temp_str = "";
			int len_str=str.size();
			bool is_sub_folder = false;
			int i=0;

			while(i<len_str){
				temp_str+=std::string(1, str[i]);++i;
				while(i<len_str){
					if(str[i]=='/'){
						break;
					}
					temp_str+=std::string(1, str[i]);
					++i;
				}

				if(root_folder.find(temp_str)!=root_folder.end()){
					is_sub_folder = true;
					break;
				}
				
			}

			if(!is_sub_folder){
				root_folder.insert(temp_str);
			}
		}

		return std::vector(root_folder.begin(), root_folder.end());
    }
};

int main(){
	Solution test;
	{
		std::vector<std::string> folder={"/a","/a/b","/c/d","/c/d/e","/c/f"};
		for(const auto &i : test.removeSubfolders(folder)){ //["/a","/c/d","/c/f"]
			std::cout << i << ' ';
		}
		std::cout << std::endl;
	}
	{
		std::vector<std::string> folder={"/a","/a/b/c","/a/b/d"};
		for(const auto &i : test.removeSubfolders(folder)){ //["/a"]
			std::cout << i << ' ';
		}
		std::cout << std::endl;
	}
	{
		std::vector<std::string> folder={"/a/b/c","/a/b/ca","/a/b/d"};
		for(const auto &i : test.removeSubfolders(folder)){ //["/a/b/c","/a/b/ca","/a/b/d"]
			std::cout << i << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}