class Solution {
private:
    void dfs(vector<vector<string>>& res, vector<string>& cnt, vector<int>& flag, int n, int row)
    {
        if (row == n)
        {
            res.push_back(cnt);
            return;
        }
        
        for (int col = 0; col < n; ++col)
        {
            if (flag[col] && flag[n+row+col] && flag[4*n-2+row-col])
            {
                flag[col] = flag[n+row+col] = flag[4*n-2+row-col] = 0;
                cnt[row][col] = 'Q';
                dfs(res, cnt, flag, n, row+1);
                cnt[row][col] = '.';
                flag[col] = flag[n+row+col] = flag[4*n-2+row-col] = 1;
            }
        }
        return;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> cnt(n, string(n, '.'));
        vector<int> flag(5*n-2, 1);
        
        dfs(res, cnt, flag, n, 0);
        
        return res;
    }
};
