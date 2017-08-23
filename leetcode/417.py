class Solution(object):
    def pacificAtlantic(self, a):
        def dfs(x, y, p):
            mask[x][y] |= p
            for i in xrange(4):
                nx, ny = x + dx[i], y + dy[i]
                if 0 <= nx < n and 0 <= ny < m and mask[nx][ny] & p == 0 and a[nx][ny] >= a[x][y]:
                    dfs(nx, ny, p)
        if not a:   return []
        n, m = len(a), len(a[0])
        dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
        mask, ans = [[0] * m for i in xrange(n)], []
        for i in xrange(n):
            dfs(i, 0, 1)
            dfs(i, m - 1, 2)
        for i in xrange(m):
            dfs(0, i, 1);
            dfs(n - 1, i, 2)
        for i in xrange(n):
            for j in xrange(m):
                if mask[i][j] == 3:
                    ans.append([i, j])
        return ans