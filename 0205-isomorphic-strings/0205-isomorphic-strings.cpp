#include <string>
#include <vector>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        // Base case: if lengths are different, they cannot be isomorphic
        if (s.length() != t.length()) return false;
        
        // Arrays to store the last seen position (+1) of each character
        // 256 size covers all standard extended ASCII characters
        int mapS[256] = {0};
        int mapT[256] = {0};
        
        for (int i = 0; i < s.length(); ++i) {
            // If the last recorded positions don't match, mapping is invalid
            if (mapS[(unsigned char)s[i]] != mapT[(unsigned char)t[i]]) {
                return false;
            }
            
            // Record the current index + 1 (using i + 1 to avoid confusion with the default 0)
            mapS[(unsigned char)s[i]] = i + 1;
            mapT[(unsigned char)t[i]] = i + 1;
        }
        
        return true;
    }
};
