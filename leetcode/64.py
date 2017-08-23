class Solution(object):
    def minPathSum(self, a):
        n, m = len(a), len(a[0])
        dp = [[10000000] * m for i in xrange(n)]
        dp[0][0] = a[0][0]
        for i in xrange(n):
            for j in xrange(m):
                if i + j == 0: 
                    continue
                if i > 0:   dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j])
                if j > 0:   dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j])
        return dp[n - 1][m - 1]