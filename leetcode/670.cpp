class Solution {
public:
    int maximumSwap(int n) {
        vector<int> a;
        for (int m = n; m; m /= 10) a.push_back(m % 10);
        int len = a.size();
        vector<int> p(10);
        p[0] = 1;
        for (int i = 1; i < 10; ++i) p[i] = p[i - 1] * 10;
        int ans = n;
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int cur = n - p[i] * a[i] + p[i] * a[j] - p[j] * a[j] + p[j] * a[i];
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};