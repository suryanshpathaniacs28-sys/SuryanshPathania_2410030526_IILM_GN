#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // Base case: An empty array has 0 unique elements
        if (nums.empty()) return 0;
        
        // 'insertIndex' tracks the position where the next unique element should be placed.
        // The element at index 0 is always unique, so we start writing from index 1.
        int insertIndex = 1;
        
        // Loop pointer 'i' scans through the array starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            // If the current element is different from the previous element,
            // it means we have found a brand new unique value!
            if (nums[i] != nums[i - 1]) {
                // Overwrite the element at 'insertIndex' with this unique value
                nums[insertIndex] = nums[i];
                // Increment 'insertIndex' to prepare for the next unique value
                insertIndex++;
            }
        }
        
        // 'insertIndex' naturally represents the count of unique elements (k)
        return insertIndex;
    }
};

