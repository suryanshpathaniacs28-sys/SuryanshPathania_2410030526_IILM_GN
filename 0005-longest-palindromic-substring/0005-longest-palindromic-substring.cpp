#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0; // Starting index of the longest palindrome found
        int maxLength = 0; // Length of the longest palindrome found
        
        // Helper lambda function to expand outwards from a given center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Return the length of the palindrome found
            // (right - 1) - (left + 1) + 1 = right - left - 1
            return right - left - 1;
        };
        
        for (int i = 0; i < s.length(); ++i) {
            // Case 1: Odd length palindromes (e.g., "aba", center is 'b')
            int len1 = expandAroundCenter(i, i);
            
            // Case 2: Even length palindromes (e.g., "cbbd", center is between 'b' and 'b')
            int len2 = expandAroundCenter(i, i + 1);
            
            // Track the maximum length found so far
            int len = std::max(len1, len2);
            
            if (len > maxLength) {
                maxLength = len;
                // Calculate the true starting position of this substring
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLength);
    }
};

