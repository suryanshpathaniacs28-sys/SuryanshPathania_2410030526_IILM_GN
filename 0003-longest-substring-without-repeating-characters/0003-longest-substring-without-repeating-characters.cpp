#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Look-up array to store the last seen index of each ASCII character.
        // Initialized to -1 to represent that no character has been visited yet.
        std::vector<int> lastSeen(256, -1);
        
        int maxLength = 0;
        int left = 0; // Left boundary of the sliding window
        
        for (int right = 0; right < s.length(); ++right) {
            unsigned char currentChar = s[right];
            
            // If the character was seen inside the current window,
            // jump the left boundary past its last occurrence.
            if (lastSeen[currentChar] >= left) {
                left = lastSeen[currentChar] + 1;
            }
            
            // Record/update the current character's index position
            lastSeen[currentChar] = right;
            
            // Calculate current window size and maximize the result
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

