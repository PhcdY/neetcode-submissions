#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26, 0);
        int maxf = 0; // Tracks the frequency of the most common character in the window
        int l = 0;
        int res = 0;
        
        for (int r = 0; r < s.size(); ++r) {
            // Add the new right character to our counts
            count[s[r] - 'A']++;
            maxf = std::max(maxf, count[s[r] - 'A']);
            
            // Current window size is (r - l + 1). 
            // If the characters we need to replace exceeds k, shrink from the left.
            while ((r - l + 1) - maxf > k) {
                count[s[l] - 'A']--;
                l++;
            }
            
            // The window is now valid, update the maximum length found
            res = std::max(res, r - l + 1);
        }
        
        return res;
    }
};
