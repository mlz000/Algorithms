class MaxStack {
public:
    /** initialize your data structure here. */
    stack<int> S;
    multiset<int> Set;
    MaxStack() {
    }
    
    void push(int x) {
        S.push(x);
        Set.insert(x);
    }
    
    int pop() {
        int t = S.top();
        S.pop();
        Set.erase(Set.find(t));
        return t;
    }
    
    int top() {
        return S.top();
    }
    
    int peekMax() {
        return *Set.rbegin();
    }
    
    int popMax() {
        stack<int> tmp;
        int t = *Set.rbegin();
        while (S.top() != *Set.rbegin()){
            tmp.push(S.top());
            S.pop();
        }
        
        S.pop();
        while (tmp.size()) {
            S.push(tmp.top());
            tmp.pop();
        }
        Set.erase(Set.find(t));
        return t;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */