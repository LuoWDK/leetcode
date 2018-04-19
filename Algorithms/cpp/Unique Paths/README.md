* Permutation solution:
	* The path number is *C(m+n-2)(m-1) = C(m+n-2)(n-1)*.
* Dynamic programming solution:
	* Initialize *dp[i][j] = 1*, then *dp[i][j] = dp[i-1][j] + dp[i][j-1]*.
