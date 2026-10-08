class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_length=0;
        int cur_length=0;
        unordered_set<int> leng;
        for (int i:nums){
            leng.insert(i);
        }

        for (int i:leng){
            if(!leng.count(i-1)){
                int cur_num = i;
                cur_length=0;

                while(leng.count(cur_num)){
                    cur_length+=1;
                    cur_num+=1;
                }
            }
            max_length=max(max_length,cur_length);
        }

    return max_length;
    }
};