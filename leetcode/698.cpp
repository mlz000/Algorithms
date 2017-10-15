bool vis[16];
bool dfs(int pos, int tot, int zu, int k, int sum, int n, vector<int>& nums) {
    if (zu == k - 1 && tot == 0)    return true;
    if (pos == n)   return false;
    for (int i = pos; i < n; ++i) {
        if (vis[i]) continue;
        if (tot + nums[i] > sum)  return false;
        vis[i] = 1;
        if (tot + nums[i] == sum) {
            if (dfs(0, 0, zu + 1, k, sum, n, nums))   return true;
        }
        else if(dfs(pos + 1, tot + nums[i], zu, k, sum, n, nums))   return true;
        vis[i] = 0;
    }
    return false;
}
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (auto& x : nums)    sum += x;
        if (sum % k != 0)   return false;
        if (k == 1) return true;
        memset(vis, 0, sizeof(vis));
        sum /= k;
        return dfs(0, 0, 0, k, sum, n, nums);
    }
};