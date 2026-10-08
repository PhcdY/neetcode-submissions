class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);// fixed nên dùng array
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> blocks(9);

    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            char cur = board[i][j];
            int block = i/3 + (j/3)*3;

            if(cur=='.'){
                continue;
            }

            if((rows[i].count(cur))||(cols[j].count(cur))||(blocks[block].count(cur))){
                return false;
            }

            else{
                rows[i].insert(cur);
                cols[j].insert(cur);
                blocks[block].insert(cur);
            }

    

        }
    }
    return true;   

    }
};
