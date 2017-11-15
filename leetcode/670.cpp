class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> dp(s.size(), s.size() - 1);
        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] <= s[dp[i + 1]])    dp[i] = dp[i + 1];
            else dp[i] = i;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[dp[i]] == s[i]) continue;
            swap(s[i], s[dp[i]]);
            break;
        }
        return stoi(s);
    }
};