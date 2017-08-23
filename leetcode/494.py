class Solution(object):
    def findTargetSumWays(self, a, S):
        n = len(a)
        if S > 1000:
            return 0
        dp = [[0] * 3001 for i in xrange(22)]
        dp[0][a[0] + 1000] += 1
        dp[0][-a[0] + 1000] += 1
        for i in xrange(1, n):
            for j in xrange(-1000, 1001):
                dp[i][a[i] + j + 1000] += dp[i - 1][j + 1000]
                dp[i][j - a[i] + 1000] += dp[i - 1][j + 1000]   
        return dp[n - 1][1000 + S]