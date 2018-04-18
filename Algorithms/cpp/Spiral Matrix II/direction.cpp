
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
		if (0 == n)
		{
			return res;
		}
		vector<int> temp1(n);
		vector<vector<int>> temp(n, temp1);
		res.swap(temp);

		int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int position[2] = {0, -1};
		int d = 0;
		int x = n, y = n, count = 1;
		while (count <= n*n)
		{
			for (int i = 0; i < y; ++i)
			{
				position[0] += direction[d][0];
				position[1] += direction[d][1];
				res[position[0]][position[1]] = count++;
			}
			d = (d + 1) % 4;
			--x;
			swap(x, y);
		}
		return res;
    }
};
