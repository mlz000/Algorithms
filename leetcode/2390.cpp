class Solution {
public:
    string removeStars(string s) {
        int cur = 0;
        string ans = "";
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '*') {
                s[i] = '?';
                ++cur;
                continue;
            }
            if (cur > 0) {
                s[i] = '?';
                --cur;
            }
        }
        for (auto c : s) {
            if (c != '?') {
                ans += c;
            }
        }
        return ans;
    }
};
