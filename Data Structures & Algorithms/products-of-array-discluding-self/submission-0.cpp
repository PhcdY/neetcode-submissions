class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> answer(n); 
        

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                answer[i] = 1;
            } else {
             
                answer[i] = nums[i - 1] * answer[i - 1]; 
            }
        }
        
        int right = 1;

        for (int i = n - 1; i >= 0; i--) {

            answer[i] = answer[i] * right;
            

            right = right * nums[i]; 
        }
        
        return answer;
    }
};
