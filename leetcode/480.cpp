#define pb push_back
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& a, int k) {
        multiset<int> S(a.begin(), a.begin() + k);
        auto it = next(S.begin(), k / 2);
        vector<double> ans;
        ans.pb((double(*it) + *prev(it, 1 - k % 2)) / 2);
        int n = a.size();
        for (int i = k; i < n; ++i) {
            S.insert(a[i]);
            if (a[i] < *it)   it--;
            if (a[i - k] <= *it) it++;
            S.erase(S.find(a[i - k]));
           ans.pb((double(*it) + *prev(it, 1 - k % 2)) / 2);
        }
        return ans;
    }
};