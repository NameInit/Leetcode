#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <cassert>


class Solution {
public:
    long long maxSubarrays(int n, std::vector<std::vector<int>>& conflictingPairs) {
        std::vector<int> bMin1(n + 1, INT64_MAX), bMin2(n + 1, INT64_MAX);
        for (const auto& pair : conflictingPairs) {
            int a = std::min(pair[0], pair[1]), b = std::max(pair[0], pair[1]);
            if (bMin1[a] > b) {
                bMin2[a] = bMin1[a];
                bMin1[a] = b;
            } else if (bMin2[a] > b) {
                bMin2[a] = b;
            }
        }
        long long res = 0;
        int ib1 = n, b2 = INT64_MAX;
        std::vector<long long> delCount(n + 1, 0);
        for (int i = n; i >= 1; i--) {
            if (bMin1[ib1] > bMin1[i]) {
                b2 = std::min(b2, bMin1[ib1]);
                ib1 = i;
            } else {
                b2 = std::min(b2, bMin1[i]);
            }
            res += std::min(bMin1[ib1], n + 1) - i;
            delCount[ib1] +=
                std::min(std::min(b2, bMin2[ib1]), n + 1) - std::min(bMin1[ib1], n + 1);
        }
        return res + *std::max_element(delCount.begin(), delCount.end());
    }
};

int main(){
	return 0;
}