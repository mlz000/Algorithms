struct data {
    int cnt, pos, x;
};
bool operator < (const data &a, const data &b) {
    if (a.cnt != b.cnt) return a.cnt > b.cnt;
    return a.pos > b.pos;
}

class FreqStack {
public:
    int tot;
    unordered_map<int, int> count;
    set<data> s;
    FreqStack() {
        tot = 0;
        count.clear();
        s.clear();
    }
    
    void push(int x) {
        s.insert(data{++count[x], ++tot, x});
    }
    
    int pop() {
        data t = *s.begin();
        int ans = t.x;
        --count[ans];
        s.erase(s.begin());
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
