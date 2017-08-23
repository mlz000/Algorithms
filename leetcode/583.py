class Solution(object):
    def minDistance(self, s1, s2):
        s1 = "?" + s1
        s2 = "?" + s2
        n, m = len(s1), len(s2)
        dp = [[0] * (m + 1) for i in xrange(n + 1)]
        for i in xrange(1, n):
            for j in xrange(1, m):
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                if s1[i] == s2[j]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
        return (n - dp[n - 1][m - 1] - 1) + (m - 1 - dp[n - 1][m - 1])