
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty()){
			return res;
		}

		res = matrix[0];
		int n = matrix.size(), m = matrix[0].size();
		int direction[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
		int position[2] = {0, m-1};
		int count = m * (n-1);
		int d = 0;
		while (count)
		{
			--n;
			swap(m, n);
			for (int i = 0; i < m; ++i)
			{
				position[0] += direction[d][0];
				position[1] += direction[d][1];
				res.push_back(matrix[position[0]][position[1]]);
			}
			d = (d+1) % 4;
			count -= m;
		}
        return res;
	}
};
