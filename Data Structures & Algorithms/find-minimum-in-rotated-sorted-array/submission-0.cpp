class Solution {
public:
    int findMin(vector<int> &nums) {
        int r = nums.size()-1;
        int l = 0;
        int mid;

        while(l<r){
            mid = (l+r)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            if(nums[mid]<nums[r]){
                r=mid;
            }
        }

        return nums[l];
    }
};
