#define pb push_back
bool cmp(const Interval& a, const Interval &b) {
    return a.start < b.start || (a.start == b.start && a.end < b.end);
}
class Solution {
public:
    vector<Interval> ans;
    vector<Interval> merge(vector<Interval>& a) {
        sort(a.begin(), a.end(), cmp);
        a.pb(Interval(10000000, 10000000));
        int n = a.size(), l, r;
        if (n == 0) return ans;
        l = a[0].start, r = a[0].end;
        for (int i = 1; i < n; ++i) {
            if (a[i].start <= r && r <= a[i].end) r = a[i].end;
            else if (a[i].start > r) {
                ans.pb(Interval(l, r));
                l = a[i].start, r = a[i].end;
            }
        }
        return ans;
    }
};