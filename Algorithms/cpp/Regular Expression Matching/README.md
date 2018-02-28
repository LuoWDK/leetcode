* Recursion solution:
	* It will cost 41 ms.
* Recursion solution with memory search:
	* It will cost 10 ms.
	* **Dynamic two demension array** is hard to definition in C++. Hence, **vector** is prefered for definition. 
* Dynamic programming solution: it will coat 12 ms.
	* initialize dp[0][*]
	* if p[j] = \*, dp[i+1][j+1] = dp[i+1][j] || dp[i+1][j-1]
		*  **...a...** vs **...a\*...**
		*  **...a...** vs **...ab\*...**
	*  else if p[j] matches s[i], dp[i+1][j+1] = dp[i][j] || dp[i][j-1]
		*  **123a...** vs **123a...**
		*  **123aa...** vs **123a\*...**
