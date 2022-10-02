class Solution {
public:
    int cnt[10];
    string largestPalindromic(string num) {
        for (auto c : num) {
           ++cnt[c - '0'];
        }
        int left = -1;
        string s = "";
        for (int i = 9; i >= 0; --i) {
            if (!cnt[i])    continue;
            if (!i && s.empty()) {
                if (left == -1) return "0";
            }
            if (cnt[i] >= 2) {
                if (!(i == 0 && s.empty())) {
                    s += string(cnt[i] / 2, '0' + i);
                }
            }
            if (cnt[i] & 1) {
                if (left == -1) {
                    left = i;
                }
            }
        }
        if (~left) {
            return s + string(1, '0' + left) + string(s.rbegin(), s.rend());
        } else {
            return s + string(s.rbegin(), s.rend());
        }
    }
};
