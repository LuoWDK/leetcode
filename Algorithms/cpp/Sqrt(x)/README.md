* Sqrt solution:
	* Return **floor( sqrt(x) )**.
* Bit solution:
	* We iterate 16 bit to check that whether current binary number is answer.
* Binary solution:
	* We binary search the answer in [1, x].
* Newton's iterative solution:
	1 Let **f(x) = x^2 - S**, then **f'(x) = 2x**.
	2 Given **(x0, y0)** have **f(x0) = y0**, then the tangent line be **y = kx + b** with **-b/k = (x0+S/x0) /2**.
	3 Since when **x = -b/k**, **y = 0**.
	4 Hence, ***(-b/k, f(-b/k))* if much closer to **0**.
    5 Thus, we iterates finding the tangent line, the intersection between **y = 0** and the tangent line will be much closer to the answer.
    6 Overall, **ans = (ans + x / ans) / 2**.
