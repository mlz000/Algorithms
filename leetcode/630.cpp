class Solution {
public:
    int scheduleCourse(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](vector<int> a, vector<int> b) {return a[1] < b[1];});
        priority_queue<int> pq;
        int now = 0;
        for (auto &t : a) {
            pq.push(t[0]);
            now += t[0];
            if (now > t[1]) {
                now -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};