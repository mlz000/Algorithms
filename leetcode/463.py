class Solution(object):
    def islandPerimeter(self, a):
        if not a:
            return 0
        def gao(i, j):
            dir = (i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1),
            res = 0
            for x, y in dir:
                if x < 0 or y < 0 or x == len(a) or y == len(a[0]) or a[x][y] == 0:
                    res += 1
            return res
        cnt = 0
        for i in xrange(len(a)):
            for j in xrange(len(a[0])):
                if a[i][j] == 1:
                    cnt += gao(i, j)
        return cnt