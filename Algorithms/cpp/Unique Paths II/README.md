* Dynamic programming solution:
	* If index *(i, j)* has no obstacle, then *dp[i][j] = dp[i-1][j] + dp[i][j-1]*.
	* Else if index *(i, j)* has obstacles, then *dp[i][j] = 0*.
