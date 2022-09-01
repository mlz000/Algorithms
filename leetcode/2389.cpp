class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans(queries.size());
        vector<std::pair<int, int>> q;
        for (int i = 0; i < queries.size(); ++i) {
            q.emplace_back(std::make_pair(queries[i], i));
        }
        std::sort(q.begin(), q.end());
        std::sort(nums.begin(), nums.end());
        int now = -1;
        long long sum = 0;
        for (auto pair: q) {
            while(now + 1 < nums.size() && nums[now + 1] + sum <= pair.first) {
                ++now;
                sum += nums[now];
            }
            ans[pair.second] = now + 1;
        }
        return ans;
    }
};
