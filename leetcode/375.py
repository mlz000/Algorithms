class Solution(object):
    def getMoneyAmount(self, n):
        def gao(l, r):
            if l >= r:   return 0
            if l + 1 == r:  return l
            if dp[l][r] != -1:  return dp[l][r]
            dp[l][r] = 100000
            for i in xrange(l + 1, r):
                dp[l][r] = min(dp[l][r], max(gao(l, i - 1), gao(i + 1, r)) + i)
            return dp[l][r]
        dp = [[-1] * (n + 1) for i in xrange(n + 1)]
        return gao(1, n)