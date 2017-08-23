class Solution(object):
    def longestPalindromeSubseq(self, s):
        def gao(l, r):
            if l > r:
                return 0
            if l == r:
                dp[l][r] = 1
                return dp[l][r]
            if dp[l][r] != -1:
                return dp[l][r]
            dp[l][r] = 0
            if s[l] == s[r]:
                dp[l][r] = max(dp[l][r], gao(l + 1, r - 1) + 2)
            else:
                dp[l][r] = max(gao(l, r - 1), gao(l + 1, r))
            return dp[l][r]
        n = len(s)
        dp = [[-1] * n for i in xrange(n)]
        return gao(0, n - 1)