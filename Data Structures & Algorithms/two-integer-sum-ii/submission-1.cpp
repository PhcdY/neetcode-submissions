class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        vector<int> result;

        int sum=numbers[left]+numbers[right];
        while (sum!=target){
            if (sum<target){
                left +=1;
                sum=numbers[left]+numbers[right];
            }
            else if(sum>target){
                right -=1;
                sum=numbers[left]+numbers[right];               
            }

        }
        result.push_back(left+1);
        result.push_back(right+1);
        return result;
    }
};
