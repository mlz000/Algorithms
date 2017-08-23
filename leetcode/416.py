class Solution(object):
    def canPartition(self, a):
        n = len(a)
        tot = sum(a)
        if tot % 2 == 1:
            return False
        dp = [False] * 20001
        dp[0] = True
        for i in xrange(n):
            for j in xrange(10000, a[i] - 1, -1):
                dp[j] |= dp[j - a[i]]
        return dp[tot / 2]