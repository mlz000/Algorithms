class Solution(object):
    def lengthOfLongestSubstring(self, s):
        r = -1
        ans = 0
        l = len(s)
        dict = {}
        for i in range(l):
            while r + 1 < l:
                if s[r + 1] not in dict or dict[s[r + 1]] == 0:
                    r += 1;
                    dict[s[r]] = 1
                else:
                    break
            ans = max(ans, r - i + 1)
            dict[s[i]] = 0
        return ans