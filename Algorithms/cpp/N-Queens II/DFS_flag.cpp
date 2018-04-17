class Solution {
private:
    void DFS(int& res, vector<int>& flag, int n, int row)
    {
        if (row == n)
        {
            ++res;
            return;
        }
        
        for (int col = 0; col < n; ++col)
        {
            if (flag[col] && flag[n+row+col] && flag[4*n-2+row-col])
            {
                flag[col] = flag[n+row+col] = flag[4*n-2+row-col] = 0;
                DFS(res, flag, n, row+1);
                flag[col] = flag[n+row+col] = flag[4*n-2+row-col] = 1;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<int> flag(5*n, 1);
        int res = 0;
        DFS(res, flag, n, 0);
        return res;
    }
};
