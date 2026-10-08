class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int max_size = 0; 

        while (l < r) {

            int width = r - l;
            int current_height = min(heights[l], heights[r]);
            

            int current_size = current_height * width;
            max_size = max(max_size, current_size);

            // 3. hi bước vào, width sẽ giảm, nên size chỉ tăng khi height tăng, height lại là min của các cột nên chắc chắn phải bỏ cột thấp hơn giawux l và r dù nnao
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return max_size;   
    }
};