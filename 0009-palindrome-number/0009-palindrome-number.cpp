class Solution {
public:
    bool isPalindrome(int x) {
        // Edge Cases:
        // 1. Negative numbers are not palindromes due to the '-' sign (e.g., -121).
        // 2. Numbers ending in 0 are not palindromes unless the number is 0 itself (e.g., 10).
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        
        // Keep moving digits to reversedHalf until we reach the middle of the number
        while (x > reversedHalf) {
            int lastDigit = x % 10;
            reversedHalf = reversedHalf * 10 + lastDigit;
            x /= 10;
        }

        // For even-length numbers (e.g., 1221): x == reversedHalf (12 == 12)
        // For odd-length numbers (e.g., 121): x == reversedHalf / 10 (1 == 12 / 10)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
