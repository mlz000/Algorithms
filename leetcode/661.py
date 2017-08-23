class Solution(object):
    def imageSmoother(self, a):
        n, m = len(a), len(a[0])
        b = [[0] * m for i in xrange(n)]
        for i in xrange(n):
            for j in xrange(m):
                now, t = 0, 0
                for dx in [-1, 0, 1]:
                    for dy in [-1, 0, 1]:
                        x, y = i + dx, j + dy
                        if 0 <= x < n and 0 <= y < m:
                            now += a[x][y]
                            t += 1
                b[i][j] = int(math.floor(now / t))
        return b