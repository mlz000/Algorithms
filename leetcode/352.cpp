#define pb push_back
class SummaryRanges {
public:
    void addNum(int val) {
        auto it = S.lower_bound(Interval(val, val));
        int st = val, ed = val;
        if (it != S.begin() && (--it) -> end + 1 < val)    ++it;
        while (it != S.end() && it -> start <= val + 1 && it -> end >= val - 1) {
            st = min(st, it -> start);
            ed = max(ed, it -> end);
            it = S.erase(it);
        }
        S.insert(it, Interval(st, ed));
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> ans;
        for (auto x : S)    ans.pb(x);
        return ans;
    }
private:
    struct cmp{
        bool operator()(Interval a, Interval b){ 
            return a.start < b.start; 
        }
    };
    set<Interval, cmp> S;
};