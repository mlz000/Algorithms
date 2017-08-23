class Solution(object):
    def numIslands(self, a):
        def dfs(x, y, n, m, a):
            if v[x][y]: return
            v[x][y] = True
            if x + 1 < n and a[x + 1][y] == '1':   dfs(x + 1, y, n, m, a)
            if x >= 1 and a[x - 1][y] == '1':   dfs(x - 1, y, n, m, a)
            if y + 1 < m and a[x][y + 1] == '1':    dfs(x, y + 1, n, m, a)
            if y >= 1 and a[x][y - 1] == '1':   dfs(x, y - 1, n, m, a)
        n = len(a)
        if n == 0:  return 0
        m = len(a[0])
        ans, v = 0, [[False] * m for i in xrange(n)]
        for i in xrange(n):
            for j in xrange(m):
                if a[i][j] == '1' and not v[i][j]:
                    ans += 1
                    dfs(i, j, n, m, a)
        return ans