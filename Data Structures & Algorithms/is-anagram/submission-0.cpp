class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()){
            return false;
        }

        unordered_map<char,int> countMap;

        for (char c : s){
            countMap[c]++;//nếu chưa có thì C++ tự biết cách tạo = 0 r +1
        }

        for (char c : t){
            if((countMap.find(c)==countMap.end())||(countMap[c]==0)){
                return false;
            }
            else{
                countMap[c]--;
            }
        }
        return true;

    }
};