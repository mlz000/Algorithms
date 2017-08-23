class Solution(object):
    def characterReplacement(self, s, k):
        n = len(s)
        cnt = [0] * 26
        l, mx = 0, 0
        ans = 0
        for r in xrange(n):
            t = ord(s[r]) - ord('A');
            cnt[t] += 1
            mx = max(mx, cnt[t])
            while r - l + 1 - mx > k:
                tt = ord(s[l]) - ord('A')
                cnt[tt] -= 1
                l += 1
                mx = max(cnt[i] for i in xrange(26)) 
            ans = max(ans, r - l + 1)
        return ans