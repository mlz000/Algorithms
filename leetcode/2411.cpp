class Solution {
public:
    queue<int> q[32];
    vector<int> ans;
    vector<int> smallestSubarrays(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j <= 31; ++j) {
                if (nums[i] >> j & 1) {
                    q[j].push(i);
                }
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            int now = i;
            for (int j = 31; j >= 0; --j) {
                while (q[j].size() && q[j].front() < i) {
                    q[j].pop();
                }
                if (q[j].size()) {
                    now = max(now, q[j].front());
                }
            }
            ans.emplace_back(now - i + 1);
        }
        return ans;
    }
};
