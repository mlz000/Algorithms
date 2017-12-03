class MyCalendarThree {
public:
    map<int, int> G;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        ++G[start];
        --G[end];
        int mx = 0, t = 0;
        for (auto& x : G) {
            t += x.second;
            mx = max(mx, t);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */