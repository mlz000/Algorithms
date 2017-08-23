class Solution(object):
    def coinChange(self, a, tot):
        n = len(a)
        dp = [100000] * (tot + 1)
        dp[0] = 0
        for i in xrange(0, n):
            if a[i] > tot:  continue
            for j in xrange(a[i], tot + 1):
                dp[j] = min(dp[j], dp[j - a[i]] + 1)
        return dp[tot] if dp[tot] != 100000 else -1