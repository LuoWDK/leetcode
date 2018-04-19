* Dynamic programming solution:
	* The problem is similar to problem **62 & 63**.
	* Hence, we have *dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]*.
