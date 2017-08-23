class Solution(object):
    def minDistance(self, s, t):
       n, m = len(s), len(t)
       dp = [[10**6] * (m + 1) for i in xrange(n + 1)]
       for i in xrange(n + 1):   dp[i][0] = i
       for j in xrange(m + 1):   dp[0][j] = j
       for i in xrange(1, n + 1):
           for j in xrange(1, m + 1):
               dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1)
               if s[i - 1] == t[j - 1]: dp[i][j] = min(dp[i][j], dp[i - 1][j - 1])
       return dp[n][m]