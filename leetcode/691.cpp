/*
We are given N different types of stickers. Each sticker has a lowercase English word on it.

You would like to spell out the given target string by cutting individual letters from your collection of stickers and rearranging them.

You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

What is the minimum number of stickers that you need to spell out the target? If the task is impossible, return -1.
Input:

["with", "example", "science"], "thehat"
Output:

3
*/
int n, m, dp[1 << 15];
class Solution {
public:
    int minStickers(vector<string>& s, string target) {
        n = s.size(), m = target.size();
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < 1 << m; ++i) {
            if (dp[i] == 0x3f3f3f3f)    continue;
            for (int j = 0; j < n; ++j) {
                int t = i;
                for (int k = 0; k < s[j].size(); ++k) {
                    for (int l = 0; l < m; ++l) {
                        if (t >> l & 1) continue;
                        if (target[l] == s[j][k]) {
                            t |= 1 << l;
                            break;
                        }
                    }
                }
                dp[t] = min(dp[t], dp[i] + 1);
            }
        }
        return dp[(1 << m) - 1] == 0x3f3f3f3f ? -1 : dp[(1 << m) - 1];
    }
};