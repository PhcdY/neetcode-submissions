class Solution {
public:
  
    int fixed(string& s, int cur, int direction) {


        while (cur >= 0 && cur < s.length() && !isalnum(s[cur])) {
            cur += direction;
        }
        return cur;
    }

    bool isPalindrome(string s) {
        int len = s.length();
        int left = 0;
        int right = len - 1; 

        while (left < right) { 
            left = fixed(s, left, 1);
            right = fixed(s, right, -1);
            

            if (left >= right) {
                break;
            }

            if (s[left] >= 'A' && s[left] <= 'Z') {
                s[left] = s[left] + 32; 
            }
            if (s[right] >= 'A' && s[right] <= 'Z') {
                s[right] = s[right] + 32; 
            }
            
            if (s[left] != s[right]) {
                return false;
            }
            
            left += 1;
            right -= 1; 
        }
        
        return true; 
    }
};