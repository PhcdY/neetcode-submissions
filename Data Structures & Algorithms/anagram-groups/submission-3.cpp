#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:

    string getKey(const string& s) {
        int count[26] = {0}; 
        

        for (char c : s) {
            count[c - 'a']++;
        }
        

        string key = "";
        for (int i = 0; i < 26; i++) {
            // Cú pháp to_string() giúp biến số int thành chữ
            // Cộng thêm "#" để ngăn cách
            key += to_string(count[i]) + "#"; 
        }
        
        return key; 
        // Ví dụ chữ "eat" sẽ trả về: "1#0#0#0#1#0#0...#1#...0#"
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> myMap;
        
        for (string s : strs) {

            string currentKey = getKey(s);
            

            myMap[currentKey].push_back(s);
        }

        vector<vector<string>> result;
        for (auto pair : myMap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};


// dùng string để hash -> được dùng hash default của C++ nma sẽ tốn memory hơn
