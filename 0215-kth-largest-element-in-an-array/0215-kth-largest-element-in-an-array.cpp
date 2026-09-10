#include <vector>
#include <algorithm>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // Sorting the vector in ascending order
        std::sort(nums.begin(), nums.end());
        
        // Returning the kth largest element (0-based indexing)
        return nums[n - k];
    }
};
