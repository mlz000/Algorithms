class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int n = a.size();
        vector<int> f(n + 2, 1000000);
        f[0] = f[1] = 0;
        for (int i = 2; i <= n; ++i)
            f[i] = min(f[i], min(f[i - 1] + a[i - 1], f[i - 2] + a[i - 2]));
        return f[n];
    }
};