#define pb push_back
class Solution {
private:
    unordered_map<int, int> G;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        G.clear();
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (G.count(target - nums[i])) {
                ans.pb(G[target - nums[i]]);
                ans.pb(i);
                break;
            }
            G[nums[i]] = i;
        }
        return ans;
    }
};