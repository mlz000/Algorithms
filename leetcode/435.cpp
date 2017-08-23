class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;      
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){return a.start < b.start;});
        int res = 0, n = intervals.size(), endLast = intervals[0].end;
        for (int i = 1; i < n; ++i) {
            int t = endLast > intervals[i].start ? 1 : 0;
            endLast = t == 1 ? min(endLast, intervals[i].end) : intervals[i].end;
            res += t;
        }
        return res;
    }
};