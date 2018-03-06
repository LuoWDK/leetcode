class Solution {
private:
    bool check(vector<vector<char>>& board, int i, int j, char num){
        int ix, jx, k;
        for (k = 0; k < 9; ++k){
            if (num == board[k][j])
                return false;
            if (num == board[i][k])
                return false;
            ix = i / 3 * 3 + k / 3;
            jx = j / 3 * 3 + k % 3;
            if (num == board[ix][jx])
                return false;
        }
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board, int i, int j){
        if (9 == i)
            return true;
        if (9 == j)
            return backtract(board, i+1, 0);
        if ('.' != board[i][j])
            return backtract(board, i, j+1);
        for (int k = 1; k < 10; ++k){
            if (check(board, i, j, k+'0')){
                board[i][j] = '0' + k;
                if (backtract(board, i, j+1))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};
