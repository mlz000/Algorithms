class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int sum, sz;
    MovingAverage(int size) {
        this -> sz = size;
        sum = 0;
        while (q.size())    q.pop();
    }
    
    double next(int val) {
        if (q.size() < sz)  sum += val, q.push(val);
        else {
            sum -= q.front();
            q.pop();
            sum += val;
            q.push(val);
        }
        return (double)sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */