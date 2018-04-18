/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comp(const Interval& I1, const Interval& I2)
{
    if (I1.start == I2.start)
    {
        return I1.end < I2.end;
    }
    return I1.start < I2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		if (intervals.empty())
		{
			return res;
		}
        sort(intervals.begin(), intervals.end(), comp);
		Interval temp = intervals[0];
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i].start <= temp.end)
			{
				temp.end = max(temp.end, intervals[i].end);
			}
			else
			{
				res.push_back(temp);
				temp = intervals[i];
			}
		}
        res.push_back(temp);
		return res;
    }
};
