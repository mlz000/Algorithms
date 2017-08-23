class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_map<int, bool>> dp;
        dp[0][0] = 1;
        for (auto now : stones) {
            for (auto x : dp[now]) {
                if (x.first > 1) dp[now + x.first - 1][x.first - 1] = 1;
                dp[now + x.first][x.first] = 1;
                dp[now + x.first + 1][x.first + 1] = 1;
            }
        }
        return !dp[stones.back()].empty();
    }
};