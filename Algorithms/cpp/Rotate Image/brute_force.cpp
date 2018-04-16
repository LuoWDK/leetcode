class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (0 == matrix.size())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> res;
        res.resize(n);
        for (int i = 0; i < n; ++i)
        {
            res[i].resize(m);
            for (int j = 0; j < m; ++j)
            {
                res[i][j] = matrix[m-j-1][i];
            }
        }
        swap(matrix, res);
    }
};
