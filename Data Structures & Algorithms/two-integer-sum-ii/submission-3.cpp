class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        vector<int> result;

        int sum=numbers[left]+numbers[right];
        while (left<right){
            sum=numbers[left]+numbers[right];

            if (sum==target){
                break;
            }

            else if (sum<target){
                left +=1;

            }
            else if(sum>target){
                right -=1;    
            }

        }

        return {left+1,right+1};
    }
};
