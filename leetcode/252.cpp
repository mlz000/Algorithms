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
    bool canAttendMeetings(vector<Interval>& a) {
        sort(a.begin(), a.end(), [](Interval p, Interval q) {return p.start < q.start;});
        for (int i = 1; i < a.size(); ++i) {
            if (a[i].start < a[i - 1].end) return 0;
        }
        return 1;
    }
};