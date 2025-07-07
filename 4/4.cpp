#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            std::swap(nums1, nums2);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half_len = (total + 1) / 2;
        
        int imin = 0, imax = m;
        double max_left = 0, min_right = 0;
        
        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = half_len - i;
            
            int A_left = (i > 0) ? nums1[i-1] : INT_MIN;
            int A_right = (i < m) ? nums1[i] : INT_MAX;
            int B_left = (j > 0) ? nums2[j-1] : INT_MIN;
            int B_right = (j < n) ? nums2[j] : INT_MAX;
            
            if (A_left <= B_right && B_left <= A_right) {
                if (total % 2 == 1) {
                    return std::max(A_left, B_left);
                } else {
                    max_left = std::max(A_left, B_left);
                    min_right = std::min(A_right, B_right);
                    return (max_left + min_right) / 2.0;
                }
            } else if (A_left > B_right) {
                imax = i - 1;
            } else {
                imin = i + 1;
            }
        }
        
        return 0.0;
    }
};

int main(){
	Solution test;
	{
		std::vector<int> v1={1,2,3,9,10};
		std::vector<int> v2={4,5,6,7,8};
		std::cout << test.findMedianSortedArrays(v1, v2) << std::endl;
	}
	return 0;
}