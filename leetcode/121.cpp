class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        vector<int> mx(n, a[n - 1]);
        for (int i = n - 2; i >= 0; --i)    mx[i] = max(mx[i + 1], a[i]);
        int ans = 0;
        for (int i = 0; i < n; ++i) ans = max(ans, mx[i] - a[i]);
        return ans;
    }
};