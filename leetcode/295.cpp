typedef long long LL;
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int> > large;
    priority_queue<int> small;
    void addNum(int num) {
        if (small.empty()) small.push(num);
        else if (num <= small.top())    small.push(num);
        else large.push(num);
        if (small.size() > large.size() + 1)  large.push(small.top()), small.pop();
        else if (large.size() > small.size())   small.push(large.top()), large.pop();
    }
    
    double findMedian() {
        if ((small.size() + large.size()) & 1)  return (double)small.top();
        else return ((double)small.top() + large.top()) / 2;
    }
};