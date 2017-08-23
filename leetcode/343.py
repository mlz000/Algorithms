class Solution(object):
    def integerBreak(self, n):
        dp = [0] * (n + 1)
        dp[1] = 1
        for i in xrange(2, n + 1):
            for j in xrange(1, i):
                dp[i] = max(dp[i], dp[j] * (i - j))
                if i != n:
                    dp[i] = max(dp[i], i)
        return dp[n]