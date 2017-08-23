class Solution(object):
    def updateMatrix(self, a):
        q, n, m = [], len(a), len(a[0])
        for i in xrange(n):
            for j in xrange(m):
                if a[i][j] != 0:
                    a[i][j] = 1000000
                else:
                    q.append((i, j))
        for i, j in q:
            for r, c in ((i, j + 1), (i, j - 1), (i + 1, j), (i - 1, j)):
                z = a[i][j] + 1
                if 0 <= r < n and 0 <= c < m and a[r][c] > z:
                    a[r][c] = z
                    q.append((r, c))
        return a