
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
		int n = matrix.size(), m = matrix[0].size();

		int left = 0, right = m-1, top = 0, buttom = n-1, ind = 0;
		while (top <= buttom && left <= right)
		{
			for (int k = left; k <= right; ++k)
			{
				res.push_back(matrix[top][k]);
			}
			++top;
			for (int k = top; k <= buttom; ++k)
			{
				res.push_back(matrix[k][right]);
			}
			--right;
			if (top <= buttom && left <= right)
			{
				for (int k = right; k >= left; --k)
				{
					res.push_back(matrix[buttom][k]);
				}
				--buttom;
				for (int k = buttom; k >= top; --k)
				{
					res.push_back(matrix[k][left]);
				}
				++left;
			}
		}
		return res;
	}
};
