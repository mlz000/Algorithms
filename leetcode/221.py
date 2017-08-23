class Solution(object):
    def maximalSquare(self, a):
        n = len(a)
        if n == 0:  return 0
        m = len(a[0])
        u = [[0] * m for i in range(n)]
        l = [[0] * m for i in range(n)]
        r = [[0] * m for i in range(n)]
        ans = 0
        for i in xrange(0, n):
            lo, ro = -1, m
            for j in xrange(0, m):  
                if a[i][j] == '0':  
                    lo = j
                    u[i][j] = l[i][j] = 0
                else:
                    u[i][j] = 1 if i == 0 else u[i - 1][j] + 1
                    l[i][j] = lo + 1 if i == 0 else max(lo + 1, l[i - 1][j])
            for j in xrange(m - 1, -1, -1):
                if a[i][j] == '0':    r[i][j], ro = m, j
                else:
                    r[i][j] = ro - 1 if i == 0 else min(ro - 1, r[i - 1][j])
                    mn = min(u[i][j], r[i][j] - l[i][j] + 1)
                    ans = max(ans, mn * mn)
        return ans