#include <vector>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        int res = right;

        while (left <= right) {
            int k = left + (right - left) / 2;
            
            // Use long long to prevent integer overflow during the sum
            long long hours = 0;
            for (int p : piles) {
                // Integer math trick for ceiling division: ceil(p / k)
                hours += (p + k - 1) / k; 
            }
            
            if (hours <= h) {
                res = k;
                right = k - 1;
            } else {
                left = k + 1;
            }
        }
        
        return res;
    }
};