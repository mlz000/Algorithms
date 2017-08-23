class Solution(object):
    def isMatch(self, s, p):
        n = len(s)
        m = len(p)
        dp = [([False] * (m + 1)) for i in range(n + 1)]
        dp[0][0] = True
        for i in range(0, n + 1):
            for j in range(1, m + 1):
                if p[j - 1] == '*':
                    if j >= 2:
                        dp[i][j] = dp[i][j - 2]
                    if i > 0 and (s[i - 1] == p[j - 2] or p[j - 2] == '.'):
                        dp[i][j] = dp[i][j] | dp[i - 1][j]
                else:
                    if i > 0 and (s[i - 1] == p[j - 1] or p[j - 1] == '.'):
                        dp[i][j] = dp[i - 1][j - 1]
        return dp[n][m]