class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        short rows[9] = {0}, cols[9] = {0}, grids[9] = {0};
        short index;
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                if ('.' != board[i][j]){
                    index = 1 << (board[i][j] - '0');
                    if (rows[i] & index || cols[j] & index || grids[i/3*3+j/3] & index)
                        return false;
                    rows[i] |= index;
                    cols[j] |= index;
                    grids[i/3*3+j/3] |= index;
                }
            }
        }
        return true;
    }
};
