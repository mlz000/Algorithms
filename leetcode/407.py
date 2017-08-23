class Solution(object):
    def trapRainWater(self, a):
       if len(a) == 0:  return 0
       n, m = len(a), len(a[0])
       h = [[1000000] * m for i in xrange(n)]
       q = []
       dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
       for i in xrange(n):
           for j in xrange(m):
               if i in [0, n - 1] or j in [0, m - 1]:
                   h[i][j] = a[i][j]
                   q.append((i, j))
       while q:
           x, y = q.pop(0)
           for i in xrange(0, 4):
               nx, ny = x + dx[i], y + dy[i]
               if nx >= 1 and nx < n - 1 and ny >= 1 and ny < m - 1:
                   now = max(h[x][y], a[nx][ny])
                   if h[nx][ny] > now:
                       h[nx][ny] = now
                       q.append((nx, ny))
       return sum(h[x][y] - a[x][y] for x in xrange(n) for y in xrange(m))