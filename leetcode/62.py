class Solution(object):
    def uniquePaths(self, n, m):
        c = [[0] * 205 for i in xrange(205)]
        for i in xrange(201):
            c[i][i] = c[i][0] = 1
            for j in xrange(1, i):
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1]
        return c[n + m - 2][n - 1]