/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		if (intervals.empty() || (intervals[intervals.size()-1].end < newInterval.start))
		{
			intervals.push_back(newInterval);
			return intervals;
		}

		vector<Interval> res;
		int i = 0;
		bool flag = false;
		while (i < intervals.size())
		{
			if (flag)
			{
				res.push_back(intervals[i]);
			}
			else if (intervals[i].start <= newInterval.end && intervals[i].end >= newInterval.start)
			{
				newInterval.start = min(newInterval.start, intervals[i].start);
				newInterval.end = max(newInterval.end, intervals[i].end);
			}
			else if (intervals[i].end < newInterval.start)
			{
				res.push_back(intervals[i]);
			}
			else
			{
				res.push_back(newInterval);
				res.push_back(intervals[i]);
				flag = true;
			}
			++i;
		}
        if (!flag)
            res.push_back(newInterval);
        
		return res;
    }
};
