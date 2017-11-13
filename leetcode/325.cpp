class Solution {
public:
    unordered_map<int, int> G;
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>sum(n + 1, 0);
        G.clear();
        for (int i = 1; i <= n; ++i)    sum[i] = sum[i - 1] + nums[i - 1];
        G[0] = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (G.count(sum[i] - k))    ans = max(ans, i - G[sum[i] - k]);
            if (!G.count(sum[i]))   G[sum[i]] = i;
        }
        return ans;
    }
};