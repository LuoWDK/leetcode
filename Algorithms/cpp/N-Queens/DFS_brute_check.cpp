class Solution {
private:
    bool isValid(vector<string> cnt, int n, int row, int col)
    {
        for (int i = 0; i != row; ++i)
        {
            if ('Q' == cnt[i][col])
                return false;
        }
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j)
        {
            if ('Q' == cnt[i][j])
                return false;
        }
        for (int i = row-1, j = col+1; i >= 0 && j < n; --i, ++j)
        {
            if ('Q' == cnt[i][j])
                return false;
        }
        return true;
    }
    
    void dfs(vector<vector<string>>& res, vector<string>& cnt, int n, int row)
    {
        if (row == n)
        {
            res.push_back(cnt);
            return;
        }
        
        for (int col = 0; col < n; ++col)
        {
            if (isValid(cnt, n, row, col))
            {                
                cnt[row][col] = 'Q';
                dfs(res, cnt, n, row+1);
                cnt[row][col] = '.';
            }
        }
        return;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> cnt(n, string(n, '.'));
        
        dfs(res, cnt, n, 0);
        
        return res;
    }
};
