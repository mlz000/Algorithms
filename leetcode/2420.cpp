const int N = 1e5 + 5;
class Solution {
public:
    int dp[N][2];
    vector<int> goodIndices(vector<int>& nums, int k) {
        for (int i = nums.size() - 1; i >= 0; --i) {
            dp[i][0] = dp[i][1] = 1;
            // non-increasing
            if (i == nums.size() - 1) {
                continue;
            }
            // non-increasing
            if (nums[i] >= nums[i + 1]) {
                dp[i][0] = dp[i + 1][0] + 1;
            }
            if (nums[i] <= nums[i + 1]) {
                // non-decreasing
                dp[i][1] = dp[i + 1][1] + 1;
            }
        }
        vector<int> ans;
        for (int i = k; i < nums.size() - k; ++i) {
            if (dp[i - k][0] >= k && dp[i + 1][1] >= k) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
