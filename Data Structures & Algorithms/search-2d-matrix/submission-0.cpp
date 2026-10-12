class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m*n-1;



        while(l<=r){
            int mid = (l+r)/2;
            int row_2d = mid/n;
            int col_2d = mid%n;
            int cur = matrix[row_2d][col_2d];
            if(cur>target){
                r = mid-1;
                mid = (l+r)/2;
             

            }
            else if(cur<target){
                l = mid+1;
                mid = (l+r)/2;

            }
            else{
                return true;
            }
        }

    return false;

        

    }
};
