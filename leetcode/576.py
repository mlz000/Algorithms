class Solution(object):
    def findPaths(self, R, C, N, sr, sc):
        M = 10 ** 9 + 7
        nxt = [[0] * C for _ in xrange(R)]
        nxt[sr][sc] = 1
        ans = 0
        for time in xrange(N):
            cur = nxt
            nxt = [[0] * C for _ in xrange(R)]
            for r, row in enumerate(cur):
                for c, val in enumerate(row):
                    for nr, nc in ((r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)):
                        if 0 <= nr < R and 0 <= nc < C:
                            nxt[nr][nc] += val
                            nxt[nr][nc] %= M
                        else:
                            ans += val
                            ans %= M
        return ans