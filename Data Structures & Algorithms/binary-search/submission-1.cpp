class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size();
        int m=(l+r)/2;

        if (nums[m]==target){
            return m;
        }

        

        while (nums[m]!=target && m!=r&&m!=l){
            if (nums[m]>target){
                r = m-1;
                m = (l+r)/2;
            }
            
            else if(nums[m]<target){
                l = m+1;
                m = (l+r)/2;
            }

            if (nums[m]==target){
                return m;
            }
            
        }
        return -1;
    
    }
};
