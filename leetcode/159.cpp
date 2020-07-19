class Solution {
public:
    unordered_map<char, int> cnt;
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0, r = 0, now = 0;
        int ans = 0;
        cnt.clear();
        while (r < s.size()) {
            ++cnt[s[r]];
            if (cnt[s[r]] == 1) {
                ++now;
                if (now == 3) {
                    while (l < r && cnt[s[l]]) {
                        if (--cnt[s[l++]] == 0) {
                            --now;
                        }
                        if (now == 2)   break;
                    }
                }

            }
            ans = max(ans, r - l + 1);            
            ++r;
        }
        return ans;
    }
};