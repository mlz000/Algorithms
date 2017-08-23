class Solution(object):
    def minSteps(self, n):
        def gao(n):
            if dp[n] != -1:
                return dp[n]
            dp[n] = 100000
            for i in xrange(2, n + 1):
                if n % i == 0:
                    dp[n] = min(dp[n], i + gao(n / i))
            return dp[n]
        dp = [-1] * (n + 1)
        dp[0] = dp[1] = 0
        return gao(n)