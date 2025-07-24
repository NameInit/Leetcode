#include <iostream>
#include <vector>
#include <functional>
#include <cstdint>
#include <cassert>


class Solution {
public:
    int calc(int part1, int part2, int part3) {
        return std::max(part1, std::max(part2, part3)) - std::min(part1, std::min(part2, part3));
    }

    int minimumScore(std::vector<int> &nums, std::vector<std::vector<int>> &edges) {
        int n = nums.size();
        std::vector<std::vector<int>> e(n);
        for (auto &v : edges) {
            e[v[0]].push_back(v[1]);
            e[v[1]].push_back(v[0]);
        }

        int sum = 0;
        for (int x : nums) {
            sum ^= x;
        }

        int res = INT32_MAX;
        std::function<int(int, int, int, int)> dfs2 = [&](int x, int f, int oth,
                                                     int anc) {
            int son = nums[x];
            for (auto &y : e[x]) {
                if (y == f) {
                    continue;
                }
                son ^= dfs2(y, x, oth, anc);
            }
            if (f == anc) {
                return son;
            }
            res = std::min(res, calc(oth, son, sum ^ oth ^ son));
            return son;
        };

        std::function<int(int, int)> dfs = [&](int x, int f) {
            int son = nums[x];
            for (auto &y : e[x]) {
                if (y == f) {
                    continue;
                }
                son ^= dfs(y, x);
            }

            for (auto &y : e[x]) {
                if (y == f) {
                    dfs2(y, x, son, x);
                }
            }
            return son;
        };

        dfs(0, -1);
        return res;
    }
};

int main(){
	Solution test;
	{
		std::vector<int> nums = {1,5,5,4,11};
		std::vector<std::vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
		assert(9 == test.minimumScore(nums,edges));
	}
	{
		std::vector<int> nums = {5,5,2,4,4,2};
		std::vector<std::vector<int>> edges = {{0,1},{1,2},{5,2},{4,3},{1,3}};
		assert(0 == test.minimumScore(nums,edges));
	}
	return 0;
}