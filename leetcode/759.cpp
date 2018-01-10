/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
const int inf = 1e9;
#define F first
#define S second
#define mp make_pair
#define pb push_back
class Solution {
public:
    vector<pair<int, int> > a;
    vector<Interval> ans;
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        int n = schedule.size();
        for (auto v : schedule) {
            for (auto x : v)    a.pb(mp(x.start, x.end)); 
        }
        sort(a.begin(), a.end());
        int last = -inf;
        for (auto x : a) {
            if (x.F > last) {
                if (last != -inf)    ans.pb(Interval(last, x.F));
            }
            last = max(last, x.S);
        }
        return ans;
    }
};