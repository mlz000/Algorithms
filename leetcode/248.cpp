class Solution {
public:
    vector<pair<char, char>> nums = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    int ans;
    void dfs(string low, string high, string now) {
        if (now.size() > high.size() || (now.size() > 0 && stoll(now) > stoll(high)))   return;
        if (now.size() > 0 && stoll(now) >= stoll(low) && ((now.size() > 1 && now[0] != '0') || now.size() == 1))  ++ans;
        for (auto it : nums) {
            dfs(low, high, string(1, it.first) + now + string(1, it.second));
        }
    }
    int strobogrammaticInRange(string low, string high) {
        ans = 0;
        dfs(low, high, "");
        dfs(low, high, "0");
        dfs(low, high, "1");
        dfs(low, high, "8");
        return ans;
    }
};