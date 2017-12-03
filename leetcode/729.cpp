class MyCalendar {
public:
    set<pair<int, int> > S;
    MyCalendar() {
        S.clear();
    }
    
    bool book(int start, int end) {
        int l = start, r = end - 1;
        auto it = S.upper_bound(make_pair(l, 1e9 + 1));
        if (it != S.begin()) {
            if ((--it) -> second >= l)  return 0;
            ++it;
        }
        if (it != S.end()) {
            if (it -> first <= r)   return 0;
        }
        S.insert(make_pair(l, r));
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */