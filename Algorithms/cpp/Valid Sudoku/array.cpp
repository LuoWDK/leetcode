class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false}, cols[9][9] = {false}, blocks[9][9] = {false};
        int num, blo;
        for (int i = 0; i < 9; ++i){
            for (int  j = 0; j < 9; ++j){
                if (board[i][j] != '.'){
                    num = board[i][j] - '0' - 1;
                    blo = i / 3 * 3 + j / 3;
                    if (rows[i][num] || cols[j][num] || blocks[blo][num])
                        return false;
                    rows[i][num] = cols[j][num] = blocks[blo][num] = true;
                }
            }
        }
        return true;
    }
};
