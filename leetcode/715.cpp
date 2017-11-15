typedef pair<int, int> pii;
#define mp make_pair
#define pb push_back
#define F first
#define S second
class RangeModule {
private:
    set<pii> s;
public:
    RangeModule() {
        s.clear();
    }
    
    void addRange(int left, int right) {
        auto it = s.upper_bound(mp(left, 1e9));
        int L = left, R = right;
        if (it != s.begin()) {
            if ((--it) -> S < left)    ++it;
            else {
                L = it -> F, R = max(it -> S, right);
                it = s.erase(it);
            }
        }
        while (it != s.end() && it -> F <= right) {
            R = max(it -> S, R);
            it = s.erase(it);
        }
        s.insert(mp(L, R));
    }
    
    bool queryRange(int left, int right) {
        auto it = s.upper_bound(mp(left, 1e9));
        if (it != s.begin()) {
            if ((--it) -> S >= right)  return 1;
        }
        return 0;
    }
    
    void removeRange(int left, int right) {
        auto it = s.upper_bound(mp(left, 1e9));
        int L = left, R = right;
        vector<pii> t;
        if (it != s.begin()) {
            if ((--it) -> S <= left)    ++it;
            else {
                t.pb(mp(it -> F, left));
                if (it -> S > right)   t.pb(mp(right, it -> S));
                it = s.erase(it);
            }
        }
        while (it != s.end() && it -> F < right) {
           if (it -> S > right)    t.pb(mp(right, it -> S));
            it = s.erase(it);
        }
        for (auto &x : t)   s.insert(x);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */