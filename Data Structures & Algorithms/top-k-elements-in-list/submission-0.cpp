

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Dùng Hash Map đếm tần suất
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }

        // 2. Tạo các Xô (Buckets)
        // Kích thước là nums.size() + 1 để chứa được trường hợp tần suất = N
        vector<vector<int>> buckets(nums.size() + 1);
        
        // Ném các số vào đúng xô (Index của xô = Tần suất của số đó)
        for (auto pair : countMap) {
            int number = pair.first;
            int frequency = pair.second;
            buckets[frequency].push_back(number);
        }

        // 3. Thu hoạch từ xô to nhất lùi về
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            // Nếu xô này có đồ
            for (int num : buckets[i]) {
                result.push_back(num);
                // Đủ k phần tử thì rút lui luôn
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result;
    }
};