class Solution(object):
    def setZeroes(self, a):
        n, m = len(a), len(a[0])
        r, c = 0, 0
        for j in xrange(m):
            if a[0][j] == 0:
                r = 1
        for i in xrange(n):
            if a[i][0] == 0:
                c = 1
        for i in xrange(n):
            for j in xrange(m):
                if a[i][j] == 0:
                    a[i][0] = 0
                    a[0][j] = 0
        for i in xrange(1, n):
            for j in xrange(1, m):
                if a[i][0] == 0 or a[0][j] == 0:    a[i][j] = 0
        if r == 1:
            for j in xrange(m): a[0][j] = 0
        if c == 1:
            for i in xrange(n): a[i][0] = 0
        