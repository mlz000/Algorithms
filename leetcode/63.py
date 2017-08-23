class Solution(object):
    def uniquePathsWithObstacles(self, a):
        n = len(a)
        if n == 0:  return 0
        m = len(a[0])
        f = [[0] * m for i in xrange(n)]
        if a[0][0] == 1:    return 0
        f[0][0] = 1
        for i in xrange(n):
            for j in xrange(m):
                if i == 0 and j == 0:   continue
                if a[i][j] == 1:    f[i][j] = 0
                else:  
                    if i > 0:   f[i][j] += f[i - 1][j]
                    if j > 0:   f[i][j] += f[i][j - 1]
        return f[n - 1][m - 1]