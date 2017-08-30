class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -2147483647, pre = 0;
        for (auto& t : nums) {
            pre = max(pre + t, t);
            ans = max(ans, pre);
        }
        return ans;
    }
};