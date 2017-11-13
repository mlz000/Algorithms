class Solution {
public:
    void dfs(vector<string>& ans, string now, string num, long long last, long long cur, int target) {
        if (!num.size() && cur == target) {
            ans.push_back(now);
            return;
        }
        for (int i = 1; i <= num.size(); ++i) {
            string t = num.substr(0, i);
            if (t.size() > 1 && t[0] == '0') continue;
            string nxt = num.substr(i);
            if (now.size() > 0) {
                dfs(ans, now + "+" + t, nxt, stoll(t), cur + stoll(t), target);
                dfs(ans, now + "-" + t, nxt, -stoll(t), cur - stoll(t), target);
                dfs(ans, now + "*" + t, nxt, last * stoll(t), (cur - last) + last * stoll(t), target);
            }
            else dfs(ans, t, nxt, stoll(t), stoll(t), target);
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(ans, "", num, 0, 0, target);
        return ans;
    }
};