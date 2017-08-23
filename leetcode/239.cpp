#define pb push_back
class Solution {
public:
    deque<int> dq;
    vector<int> ans;
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n = a.size();
        if (n == 0) return ans;
        for (int i = 0; i < k - 1; ++i) {
            while(dq.size() && a[i] >= a[dq.back()])   dq.pop_back();
            dq.push_back(i);
        }
        for (int i = k - 1; i < n; ++i) {
            while (dq.size() && a[i] >= a[dq.back()])   dq.pop_back();
            dq.push_back(i);
            while (dq.size() && dq.front() < i - k + 1)   dq.pop_front();
            ans.pb(a[dq.front()]);
        }
        return ans;
    }
};