class Solution(object):
    def combinationSum4(self, a, target):
        n = len(a)
        dp = [0] * (target + 1)
        dp[0] = 1
        for i in xrange(target + 1):
            for j in xrange(n):
                if i >= a[j]:
                    dp[i] += dp[i - a[j]]
        return dp[target]