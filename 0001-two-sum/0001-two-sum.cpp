#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Hash map to store: Key = Array Number, Value = Its Index position
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the required complement already exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // Complement found! Return its stored index and the current index
                return {numMap[complement], i};
            }
            
            // If not found, insert the current number and index into the map
            numMap[nums[i]] = i;
        }
        
        // Return empty vector if no solution exists (though LeetCode guarantees one)
        return {};
    }
};

