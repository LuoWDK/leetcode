* Recursive solution: 26ms
	* When all *n* numbers are unique, each position can be placed by *n* numbers.
	* Hence, each **swap** should make a new prefix.
	* Thus, only **swap** the first appearance of each number.
* Set solution: 70ms
	* It uses **STL set** to delete reduplicate permutation.
* DFS solution: 27ms
	* It is similar to the recursive solution.
	* It uses **array** to check that a new prefix is appear.
