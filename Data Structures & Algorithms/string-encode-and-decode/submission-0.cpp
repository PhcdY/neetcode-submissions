class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (string s:strs){
            int count = s.length();
            result += to_string(count);
            result += '#';
            for (char c : s){
                result += c;
            }
        }
    return result;
    }

vector<string> decode(string s) {
    vector<string> result;
    
    // Con trỏ i bắt đầu từ đầu chuỗi
    int i = 0; 
    
    while (i < s.length()) {
        // BƯỚC 1: TÌM DẤU '#'
        int j = i; 
        while (s[j] != '#') {
            j++; 
        }
        

        string so_dem_dạng_chuoi = s.substr(i, j - i);
        int length = stoi(so_dem_dạng_chuoi);
  
        string word = s.substr(j + 1, length);
        result.push_back(word);
        

        i = j + 1 + length;
    }
    
    return result;
}

    
};
