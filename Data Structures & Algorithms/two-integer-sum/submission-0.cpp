class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> myMap;
        for (int i = 0; i < nums.size(); i++){
            int cur = target - nums[i];


            if (myMap.count(nums[i])){ 

                return {myMap[nums[i]],i};
            }

            myMap[cur]=i;
        }
        return {};
    }
};
