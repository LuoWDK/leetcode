* Brute force solution will cost 15 ms by:
	* pruning elements that are not able to reach better solution;
	* and iterating each reminder from its nearest position to its fastest position.
* Greeedy solution will cost 15 ms by:
	* set **currentPos** be the fastest position which we can reach within **step** step.
	* set **nextPos** be the next fastest position which we can reach within **step+1** step.
