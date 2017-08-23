class Solution(object):
    def numDistinct(self, s, t):
        n, m = len(s), len(t)
        dp = [[0] * (m + 1) for i in xrange(n + 1)]
        for i in xrange(n + 1): dp[i][0] = 1
        for i in xrange(1, n + 1):
            for j in xrange(1, m + 1):
                dp[i][j] += dp[i - 1][j]
                if s[i - 1] == t[j - 1]:    dp[i][j] += dp[i - 1][j - 1]
        return dp[n][m]