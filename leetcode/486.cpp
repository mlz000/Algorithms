class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        this->nums = nums;
        int len = nums.size();
        dp.resize(len, vector<int>(len));
        return func(0, len-1) >= 0;
    }
private:
    vector<int> nums;
    vector<vector<int>> dp;
    int func(int begin, int end) {
        dp[begin][end] = begin == end ? nums[begin] : max(nums[begin] - func(begin+1, end), nums[end] - func(begin, end-1));
        return dp[begin][end];
    }
};