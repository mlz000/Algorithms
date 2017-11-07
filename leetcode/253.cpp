/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval p, Interval q) {
    return p.start < q.start;
}
class Solution {
public:
    int minMeetingRooms(vector<Interval>& a) {
        sort(a.begin(), a.end(), cmp);
        priority_queue<int, vector<int>, greater<int> >pq;
        for (auto& x : a) {
            if (pq.size() && pq.top() <= x.start)   pq.pop();
            pq.push(x.end);
        }
        return pq.size();
    }
};