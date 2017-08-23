class Solution(object):
    def minimumTotal(self, a):
        n = len(a)
        if n == 0:  return a
        dp = [1000000] * n
        dp[0] = 0
        for i in xrange(n):
            for j in xrange(i, -1, -1):
                if j == 0: dp[j] += a[i][j]
                else:   dp[j] = min(dp[j - 1], dp[j]) + a[i][j]
        return min(dp)