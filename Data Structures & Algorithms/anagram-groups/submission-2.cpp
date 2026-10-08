class Solution {
public:

    struct ArrayHasher {
    size_t operator()(const array<int, 26>& arr) const {
        size_t hash = 0;
        for (int count : arr) {
            // Công thức trộn bit tiêu chuẩn để chống va chạm bộ nhớ
            hash ^= std::hash<int>{}(count) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};


// hàm hash ở trên hack ở AI để băm array bằng 

    array<int,26> myHashfunc(string s){
        array<int, 26> temp = {0};
        for (char c : s){
            temp[c-'a']++;
        }
        return temp;
        }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {


        unordered_map<array<int,26>,vector<string>,ArrayHasher> myMap; // k có hash default cho array nên phải hack, k dùng string vì array nhanh hơn
        for (string s : strs){
            auto cur = myHashfunc(s); // cur là cái vector có 26 số
            myMap[cur].push_back(s); // k cần check vì sẽ lấy full anagrams, sẽ tạo ra 1 map có các cặp key-value với value là vector string của anagram đã ghép nhóm

        }

        vector<vector<string>> result;
        for (auto pair:myMap){
            result.push_back(pair.second);
        }

    return result;

    }
};
