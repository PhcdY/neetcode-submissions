class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(128, -1); //tránh default là 0;
        int res = 0;

        int cur = 0;

        int l = 0;

        for (int i =0;i<s.size();i++){
            if(last_seen[int(s[i])]==-1){
                cur+=1;
            }

            else{
                if(l<last_seen[int(s[i])]){
                    l = last_seen[int(s[i])];
                }

                cur = i-l;
            }
            
            if(cur>res){
                res = cur;
            }
            last_seen[int(s[i])]=i;
        }
    return res;
    }
};
