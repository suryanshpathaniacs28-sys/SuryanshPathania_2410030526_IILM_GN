#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Base Case: If the array is empty, there is no common prefix
        if (strs.empty()) return "";
        
        // Step 1: Sort the array lexicographically (alphabetically)
        std::sort(strs.begin(), strs.end());
        
        // Step 2: Access the first and last strings after sorting
        std::string first = strs.front();
        std::string last = strs.back();
        
        std::string result = "";
        
        // Step 3: Compare characters of the first and last strings
        for (int i = 0; i < first.length(); ++i) {
            // As soon as characters mismatch, the common prefix ends
            if (first[i] != last[i]) {
                break;
            }
            result += first[i];
        }
        
        return result;
    }
};

