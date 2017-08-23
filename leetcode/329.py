class Solution(object):
    def longestIncreasingPath(self, a):
        def dfs(x, y):
            if dp[x][y] != 0:   return dp[x][y]
            for i in xrange(4):
                xx, yy = x + dx[i], y + dy[i]
                if xx in xrange(0, n) and yy in xrange(0, m):
                    if a[xx][yy] > a[x][y]:
                        dp[x][y] = max(dp[x][y], dfs(xx, yy))
            dp[x][y] += 1
            return dp[x][y]
            
        if len(a) == 0: return 0
        n, m, ans = len(a), len(a[0]), 0
        dp = [[0] * m for i in xrange(n)]
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        for i in xrange(n):
            for j in xrange(m):
                ans = max(ans, dfs(i, j))
        return ans