class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> cnt;
        int ans = 0, now = 0, n = s.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (cnt[s[j]] || now + 1 <= k && j < n) {
                ++cnt[s[j]];
                if (cnt[s[j]] == 1) ++now;
                ++j;
            }
            ans = max(ans, j - i);
            cnt[s[i]]--;
            if (cnt[s[i]] == 0) --now;
        }
        return ans;
    }
};